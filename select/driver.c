#include "io.h"
#include "select.h"
#include <string.h>



long count;

int main(int argc, char** argv){
    long k = atoi(argv[1]);
    long len[] = {10000, 100000, 1000000};
    int size = sizeof(len)/sizeof(long);
    char* fnames[size];
    for (int i = 0; i < size; i++){
        fnames[i] = strcat(itoa(len[i]), ".txt");
    }
    
    for (int i = 0; i < size; i++){
        char* fname = fnames[i];
        long n = len[i];
        char* s = readFile(fname);
        int* arr = A2I(s, n);
/*
        for (int i = 0; i < n; i++){
            arr[i] = arr[i] % n;
            //printf("%d  ", arr[i]);
        }
        printf("\n");
*/    
        count = 0;
        printf("%ld smallest\n", k);
        printf("%d\n", arr[selectR(arr, 0, n-1, k)]);
        printf("key comparison: %ld\n", count);
    }

    for (int i = 0; i < size; i++){
        char* fname = fnames[i];
        long n = len[i];
        char* s = readFile(fname);
        int* arr = A2I(s, n);
/*
        for (int i = 0; i < n; i++){
            arr[i] = arr[i] % n;
            //printf("%d  ", arr[i]);
        }
        printf("\n");
*/
        count = 0;
        printf("%ld smallest\n", k);
        long ind;
        if (argc != 3) {
            printf("specify 3 5 7\n");
            exit(1);
        }
        else if (*argv[2] == '3')
            ind = selectM3(arr, 0, n-1, k);
        else if (*argv[2] == '5')
            ind = selectM5(arr, 0, n-1, k);
        else if (*argv[2] == '7')
            ind = selectM7(arr, 0, n-1, k);
        else {
            printf("sepecify 3 5 7\n");
            exit(1);
        }
        printf("%d\n", arr[ind]);
        printf("key comparison: %ld\n", count);
    }    
    
    return 1;
}
