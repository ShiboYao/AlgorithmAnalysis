#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


void printarr(int**, long);
void printstr(char*);
void genVec(int, int, long);
int** A2I(char*, long*, unsigned int*);
char* readFile(char*);
void writeVec(int**, long, char*);

extern unsigned int l;


void printarr(int** a, long row){
    for (long i = 0; i < row; i++){
        for (unsigned short j = 0; j < l; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
}


void printstr(char* s){
    while (*s)
        printf("%c", *s++);
    printf("\n");
}


void writeVec(int** arr, long n, char* fname){
    FILE *f = fopen(fname, "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for (long i = 0; i < n; i++){
        for (unsigned int j = 0; j < l; j++)
            fprintf(f, "%d,", arr[i][j]);
        fprintf(f, "\n");
    }
    fclose(f);
}


void genVec(int start, int end, long n){
    time_t t;
    srand((unsigned)time(&t));

    FILE *f = fopen("data.txt", "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for(long i = 0; i < n; i++ ){
        for (unsigned int j = 0; j < l; j++)
            fprintf(f, "%d,", rand() % (end - start) + start);
        fprintf(f, "\n");
    }
    fclose(f);
}


int** A2I(char* s, long* row, unsigned int* col){
    char* p = s;
    *col = 0;
    while (*p != '\n'){
        if (*p == ',')
            (*col)++;
        p++;
    }
    while (*p){
        if (*p == '\n')
            (*row)++;
        p++;
    }
    p = s;

    int** result = malloc(sizeof(int*)*(*row));
    for (long i = 0; i < *row; i++){
        result[i] = malloc(sizeof(int)*(*col));
        for (unsigned int j = 0; j < *col; j++){
            int res = 0;
            while (*p >= '0' && *p <= '9'){
                res = res*10 + *p - '0';
                p++;
            }
            result[i][j] = res;
            p++;
        }
        p++;
    }
    
    return result;
}


char* readFile(char* fname){
    FILE* file = fopen(fname, "r");
    if (file == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* s = malloc(sizeof(char)*(fsize+1));
    fread(s, fsize, 1, file);
    s[fsize] = '\0';
    fclose(file);

    return s;
}

/*
int main(int argc, char** argv){
    char* fname = argv[1];
    char*s = readFile(fname);
    printstr(s);

    int row = 0;
    int col = 0;
    int** a = A2I(s, &row, &col);
    printarr(a, row, col);

    return 1;
}
*/

#endif
