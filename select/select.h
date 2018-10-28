#ifndef SELECT_H
#define SELECT_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


extern long count;


void swap(int*, long, long);
long partition(int*, long, long, long);
long selectR(int*, long, long, long);
long MofM(int*, long, long, int);
long selectM3(int*, long, long, long);
long selectM5(int*, long, long, long);
long selectM5(int*, long, long, long);



void swap(int* arr, long i, long j){
	if (i == j)
		return;
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

/*
long partition(int* arr, long low, long high, long p){
    swap(arr, p, high);
    long i = low, j = high-1; //bug function, very confused

    while (i < j){ //similar to quickSort on vectors but doesn't work here
        while (i < high-1 && arr[i] <= arr[high]){
            i++;
            count++;
        }
        while (j > i && arr[j] > arr[high]){
            j--;
            count++;
        }
        if (i < j){
            swap (arr, i, j);
        }
    }
    
    count++;
    swap(arr, i, high);
    //if (i < high && arr[i] > arr[high]) //very confused here
    //    swap(arr, i, high); 

    return i;
}
*/

long partition(int* arr, long low, long high, long p){
    int pivot = arr[p];
    swap(arr, p, high);
    long i = low, j = low;

    while (j < high){
        count++;
        if (arr[j] < pivot){
            swap(arr, i, j);
            i++;
        }
        j++;
    }
    swap(arr, i, high);
                       
    return i;
}


long selectR(int* arr, long low, long high, long k){
    long p = rand() % (high-low+1) + low;
    p = partition(arr, low, high, p);
    
    if (p == k-1)
        return p;
    else if (p > k-1)
        return selectR(arr, low, p-1, k);
    else
        return selectR(arr, p+1, high, k);
}


long MofM(int* arr, long low, long high, int t){
    long n = high - low;
    if (n < t)
        return selectR(arr, low, high, (low+high)/2);
    
    long l = n/t;
    int m = t/2 + 1;
    int a[l];
    long p[l];
    long j = low, i = 0;
    while (i < l){
        p[i] = selectR(arr, j, j+t-1, j+m);
        a[i] = arr[p[i++]];
        j += t;
    }
    long p_a = selectR(a, 0, l-1, l/2);

    return p[p_a];
}


long selectM3(int*arr, long low, long high, long k){
    int p = MofM(arr, low, high, 3);
    p = partition(arr, low, high, p);

    if (p == k-1)
        return p;
    else if (p > k-1)
        return selectR(arr, low, p-1, k);
    else
        return selectR(arr, p+1, high, k);
}


long selectM5(int*arr, long low, long high, long k){
    int p = MofM(arr, low, high, 5);
    p = partition(arr, low, high, p);

    if (p == k-1)
        return p;
    else if (p > k-1)
        return selectR(arr, low, p-1, k);
    else
        return selectR(arr, p+1, high, k);
}


long selectM7(int*arr, long low, long high, long k){
    int p = MofM(arr, low, high, 7);
    p = partition(arr, low, high, p);

    if (p == k-1)
        return p;
    else if (p > k-1)
        return selectR(arr, low, p-1, k);
    else
        return selectR(arr, p+1, high, k);
}


#endif
