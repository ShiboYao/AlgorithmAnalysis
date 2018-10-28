#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compVec(int*, int*);
void merge(int**, long, int**, long, int**);
void mergeSort(int**, long);
void reverse(int**, long);
void swap(int**, long, long);
void adjustHeap(int**, long, long);
void heapSort(int**, long);
long partition(int**, long, long);
void quickSort(int**, long, long);

extern unsigned long count;
unsigned int l;



int compVec(int* x, int* y){
    unsigned int i = 0;
    while (i < l){
        if (x[i] < y[i])
            return -1;  /*vec1 < vec2*/
        else if (x[i] > y[i])
            return 1; /*>*/
        else 
            i++;
    }

    return 0; /*two vectors are equal*/
}


void swap(int** a, long i, long j){ /*swap vectors*/
    int* temp = a[i];
    a[i] = a[j];
    a[j] = temp;
}


void reverse(int** a, long n){ /*reverse pointer array*/
    int i = 0;
    int j = n - 1;
    while (i < j){
        int* temp = a[i];
        a[i++] = a[j];
        a[j--] = temp;
    }
}


void merge(int** a, long m, int** b, long n, int** c){
    long i = 0;
    long j = 0;
    long k = 0;

    while (i < m && j < n){
        if (compVec(a[i], b[j]) <= 0){
            c[k++] = a[i++];
        }
        else {
            c[k++] = b[j++];
        }
        count++;
    }
    while (i < m){
        c[k++] = a[i++];
    }
    while (j < n){
        c[k++] = b[j++];
    }
}


void mergeSort(int** a, long size){
    if (size == 1)
        return;
    long mid = size / 2;
    int** left = malloc(sizeof(int*)*mid);
    int** right = malloc(sizeof(int*)*(size-mid));

    for (long i = 0; i < mid; i++){
        left[i] = malloc(sizeof(int)*l);
        left[i] = a[i];
    }
    for (long j = 0; j < size-mid; j++){
        right[j] = malloc(sizeof(int)*l);
        right[j] = a[mid+j];
    }

    mergeSort(left, mid);
    mergeSort(right, size-mid);
    merge(left, mid, right, size-mid, a);
}


void adjustHeap(int** a, long n, long i){
    long parent = i;
    long child = parent * 2 + 1;

    while (child < n){
        if (child + 1 < n && compVec(a[child], a[child+1]) < 0){
            child++;
            count++;
        }

        if (compVec(a[parent], a[child]) >= 0){
            count++;
            return;
        }
        else {
            swap(a, parent, child);
            parent = child;
            child = parent * 2 + 1;
        }
    }
}


void heapSort(int** a, long n){
    for (int i = n/2 - 1; i >= 0; i--)
        adjustHeap(a, n, i);
    
    for (int i = n - 1; i >= 0; i--){
        swap(a, 0, i);
        adjustHeap(a, i, 0);
    }
}


long partition(int** a, long low, long high){
    int* p = a[(low+high)/2];
    long i = low; /*do not skip boundary points!*/
    long j = high; /*took several hours debugging for this!*/

    while (i < j){
        while (compVec(a[i], p) < 0){
            count++;
            i++;
        }
        while (j > 0 && compVec(a[j], p) >= 0){
            count++;
            j--;
        }
        if (i < j)
            swap(a, i, j);
    }
    swap(a, i, (low+high)/2); /*swap pivot and new [index]*/

    return i;
}


void quickSort(int** a, long low, long high){
    if (low >= high)
        return;

    long index = partition(a, low, high);
    
    quickSort(a, index+1, high); /*exclude [index], right place*/
    quickSort(a, low, index-1); 
}



#endif
