#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAXLEN 50

char* readFname(char*);
int* genVec(int, int, int);
int** A2I(char**, int);
char* readFile(char*);
void writeVec(char**, int, int*, char*);

extern unsigned int l;


char* readFname(char* defaultFname){
    char* fname = malloc(sizeof(char) * MAXLEN);
    char* p = fname;
    int c;
    if ((c = getchar()) == '\n')
        strcpy(fname, defaultFname);
    else {
        *p++ = c; //should check on storage limitation and fname format
        while ((c = getchar()) != '\n')
            *p++ = c;
        *p = '\0';
    }

    return fname;
}


void writeVec(char** arr, int row, int* p, char* fname){
    FILE *f = fopen(fname, "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for (int i = 0; i < row; i++){
        char* t = arr[p[i]];
        while (*t)
            fprintf(f, "%c", *t++);
        fprintf(f, "\n");
    }
    fclose(f);
}


int* genVec(int start, int end, int n){
    time_t t;
    srand((unsigned)time(&t));
    int* sizes = malloc(sizeof(int) * n);

    FILE *f = fopen("inVec.txt", "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for(int i = 0; i < n; i++ ){
        int temp = l + rand()%6 - 3;
        sizes[i] = temp;
        for (unsigned int j = 0; j < temp-1; j++)
            fprintf(f, "%d,", rand() % (end - start) + start);
        fprintf(f, "%d\n", rand() % (end - start) + start);
    }
    fclose(f);

    return sizes;
}


char **S2A(char* s, int* row){
    char* p = s;
    *row = 0;
    while (*p){
        if (*p == '\n')
            (*row)++;
        p++;
    }
    char** result = malloc(sizeof(char*) * *row);
    p = s;
    unsigned int i = 0;
    while (*p){
        char* q = p;
        while (*p != '\n')
            p++;
        result[i] = malloc(sizeof(char) * (p-q+1)); //include '\n'
        char* t = result[i++];
        while (q < p)
            *t++ = *q++;
        *t = '\0';
        p++;
    }

    return result;
}


int** A2I(char** sentences, int row){
    int** result = malloc(sizeof(int*) * row);
    for (int i = 0; i < row; i++)
        result[i] = malloc(sizeof(int) * l);
    for (int i = 0; i < row; i++){
        int* t = result[i];
        char* p = sentences[i];
        int count = 0;
        while (*p && count < l){
            int temp = 0;
            while (*p && *p != ',')
                temp = temp*10 + *p++ - '0';
            t[count++] = temp;
            if (*p)
                p++;
        }
        while (count < l)
            t[count++] = 0;
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
