#include "select.h"

long count;

int main(int argc, char** argv){
    if (argc != 2){
        printf("specify k\n");
        exit(1);
    }
    int k = atoi(argv[1]);
    time_t t;
    srand((unsigned)time(&t));

    int n = 100;
    int arr[n];
    for (int i = 0; i < n; i++)
        arr[i] = rand() % n;

    int ind = selectM3(arr, 0, n-1, k);
    for (int i = 0; i < n; i++)
        printf("%d  ", arr[i]);
    printf("\n\n");
    printf("%d\n", arr[ind]);

    return 1;
}
