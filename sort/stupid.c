#include <stdio.h>
#include <math.h>


void swap(int* A, int i, int j){
    int temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}


void sort(int* A, int i, int k){
    if (k == 2 && A[i] > A[i+1]){
        swap(A, i, i+1);
    }
    else if (k > 2){ //ceil works, floor does not
        int m = (int)floor((double)2*k/3);
        sort(A, i, m);
        sort(A, i + k - m, m);
        sort(A, i, m);
    }
}


int main(){
    int A[] = {3,6,7,3,2,6,78,9,7,5,4,7,8,0,5,3,4,3};
    sort(A, 0, 18);
    for (int i = 0; i < 18; i++)
        printf("%i ", A[i]);

    return 1;
}
