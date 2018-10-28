#ifndef IO_H
#define IO_H

#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define MAXLINE 50


char* itoa(long);
void sriteArr(int*, long, char*);
void genArr(long, char*);
char* readFile(char*);
int* A2I(char*, long);


char* itoa(long i){
    char* s = malloc(sizeof(char) * MAXLINE);
    char* p = s;
    while (i){
        *p++ = i%10 + '0';
        i /= 10;
    }

    *p-- = '\0';
    char* q = s;
    while (p > q){
        char temp = *p;
        *p-- = *q;
        *q++ = temp;
    }

    return s;
}


void writeArr(int* arr, long n, char* fname){
    FILE* f = fopen(fname, "w");
    if (f == NULL){
        printf("Error opening file!\n");
        exit(1);
    }

    for (long i = 0; i < n; i++){
        fprintf(f, "%d,", arr[i]);
    }
    fclose(f);
}


void genArr(long n, char* fname){
    time_t t;
    srand((unsigned)time(&t));

    int arr[n];
    for (long i = 0; i < n; i++){
        arr[i] = rand() % INT_MAX; /*limit the number smaller than INT_MAX*/
    }
    writeArr(arr, n, fname);
}


char* readFile(char* fname){
    FILE* f = fopen(fname, "r");
    if (f == NULL){
        printf("Error reading file!\n");
        exit(1);
    }

    fseek(f, 0, SEEK_END);
    long fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* s = malloc(sizeof(char)*(fsize+1));
    fread(s, fsize, 1, f);
    s[fsize] = '\0';
    fclose(f);

    return s;
}


int* A2I(char* s, long n){
    int* arr = malloc(sizeof(int)*n);
    int i = 0;
    while (*s){
        int temp = 0;
        while (*s && *s != ','){
            temp = temp*10 + *s++ - '0';
        }
        if (i < n)
            arr[i++] = temp;
        s++;
    }

    return arr;
}

#endif
