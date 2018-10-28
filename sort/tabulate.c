#include "io.h"
#include "sort.h"

unsigned long count;
unsigned int l;

/*
run as tabulate settings_for_vector settings_for_sorting
run as command |&tee file.txt, to save out put in file.txt
*/

char** readSetSort(char* fname, int* row){
    char* s = readFile(fname); // read settings for sorting
    char* p = s;
    *row = 0;

    while (*p){
        if (*p == '\n'){
            (*row)++;
        }
        p++;
    }
    p = s;

    char** result = malloc(sizeof(char*)*(*row));
    for (int i = 0; i < *row; i++){
        int len = 0;
        while (*p != '\n'){
            if (*p != ',')
                len++;
            p++;
        }
        result[i] = malloc(sizeof(char)*(len+1));
        char* t = result[i];
        p = s;
        while (*p != '\n'){
            if (*p != ',')
                *t++ = *p++;
            else 
                p++;
        }
        *t = '\0';
        p++;
        s = p;
    }

    return result;
}


int** readSetVec(char* fname, int* row, int* col){
    char* s = readFile(fname); // read settings for vector generation
    char* p = s;
    *row = 0;
    *col = 0;

    while (*p != '\n'){
        if (*p == ',')
            (*col)++;
        p++;
    }
    (*col)++;
    while (*p){
        if (*p == '\n'){
            (*row)++;
        }
        p++;
    }
    p = s;
    
    int** result = malloc(sizeof(int*)*(*row));
    for (int i = 0; i < *row; i++){
        result[i] = malloc(sizeof(int)*(*col));
        int* t = result[i];
        for (int j = 0; j < *col; j++){
            *t = 0;
            while (*p != '\n' && *p != ','){
                *t = *t * 10 + *p - '0';
                p++;
            }
            t++;
            p++;
        }
    }

    return result;
}


void driveGen(int* settings){ //generate vectors
    int start = settings[0];
    int end = settings[1];
    unsigned long n = settings[2];
    l = settings[3];

    genVec(start, end, n);
}


double driveSort(char* settings){ //sorting given differeent settings
    char* fname;
    if (settings[1] == 'o')
        fname = "data.txt";
    else if (settings[1] == 's')
        fname = "aadt.txt";
    else if (settings[1] == 'r')
        fname = "tdaa.txt";
    else {
        printf("file name error\n");
        exit(1);
    }

    char* s = readFile(fname);
    long row = 0;
    int** a = A2I(s, &row, &l);

    clock_t timer = clock();
    count = 0;
    if (settings[0] == 'M')
        mergeSort(a, row);
    else if (settings[0] == 'H')
        heapSort(a, row);
    else if (settings[0] == 'Q')
        quickSort(a, 0, row-1);
    else {
        printf("sorting alg error\n");
        exit(1);
    }

    timer = clock() - timer;
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    
    if (settings[2] == 'w'){ 
        writeVec(a, row, "aadt.txt");
        reverse(a, row);
        writeVec(a, row, "tdaa.txt");
    }

    return time_taken*1000;
}


int main(int argc, char** argv){
    int rowSort;
    int rowVec, colVec;
    
    int** vec_settings = readSetVec(argv[1], &rowVec, &colVec); 
    char** sort_settings = readSetSort(argv[2], &rowSort);
    
    for (int i = 0; i < colVec; i++){
        driveGen(vec_settings[i]);
        for (int k = 0; k < colVec; k++)
            printf("%d ", vec_settings[i][k]);
        printf("\n");
        for (int j = 0; j < rowSort; j++){
            printf("%s\t", sort_settings[j]);
            printf("%.4f\t\t", driveSort(sort_settings[j]));
            printf("%lu\n", count);
        }
        printf("\n");
    }
     
    return 1;
}
