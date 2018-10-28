#include "io.h"
#include "sort.h"

unsigned long count = 0;
unsigned int l;

/*
run as ./driver sortAlg data writeOpt
e.g. ./driver M o w
which means MergeSort on Original data and Save output
{M: Merge, H: Heap, Q: Quick}
{o: Original Dataset, s: Sorted Dataset, r: Reversed Dataset}
{w: write output, NULL: do not save}
Can also >r.txt to save log info to file. 
*/

int main(int argc, char** argv){
    char* fname;
    if (argc < 3){
        printf("Specify both sorting algorithm and dataset.\n");
        exit(1);
    }

    if (*argv[1] != 'M' && *argv[1] != 'H' && *argv[1] != 'Q'){
        printf("Specify M for Merge, H for Heap or Q for Quick.\n");
        exit(1);
    }

    if (*argv[2] == 'o'){
        fname = "data.txt";
        printf("Sort on original vectors:\n");
    }
    else if (*argv[2] == 's'){
        fname = "aadt.txt";
        printf("Sort on sorted vectors:\n");
    }
    else if (*argv[2] == 'r'){
        fname = "tdaa.txt";
        printf("Sort on reversed vectors:\n");
    }
    else {
        printf("Specify o for original, s for sorted or r for reversed.\n");
        exit(1);
    }

    char* s = readFile(fname);

    long row = 0;
    int** a = A2I(s, &row, &l);

    clock_t timer = clock();

    if (*argv[1] == 'M'){
        printf("MergeSort\n");
        mergeSort(a, row);
    }
    else if (*argv[1] == 'H'){
        printf("HeapSort\n");
        heapSort(a, row);
    }
    else if (*argv[1] == 'Q'){
        printf("QuickSort\n");
        quickSort(a, 0, row-1);
    }

    timer = clock() - timer;
    printf("Key comparison %ld\n", count);
    double time_taken = ((double)timer)/CLOCKS_PER_SEC;
    printf("time taken %.6f ms\n", time_taken*1000);


    if (argc > 3 && *argv[3] == 'w'){
        writeVec(a, row, "aadt.txt");
        printf("aadt.txt saved.\n");
        reverse(a, row);
        writeVec(a, row, "tdaa.txt");
        printf("tdaa.txt saved.\n");
    }

    return 1;
}
