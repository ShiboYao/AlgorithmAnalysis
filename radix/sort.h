#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

#define MAXI 100


void countSort(int** nums, int row, int colNo, int* p){
    int output[row];
    int counter[MAXI] = {0};

    for (int i = 0; i < row; i++)
        counter[nums[p[i]][colNo]]++;
    for (int i = 1; i < MAXI; i++)
        counter[i] += counter[i-1];
    for (int i = row-1; i >= 0; i--){
        output[counter[nums[p[i]][colNo]] - 1] = p[i];
        counter[nums[p[i]][colNo]]--;
    }
    for (int i = 0; i < row; i++)
        p[i] = output[i];
}



#endif
