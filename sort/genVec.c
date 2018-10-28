#include "io.h"

unsigned int l;

/*
run as ./genVec START END NUM LEN
e.g. ./genVec 0 100 1024 5
*/

int main(int argc, char** argv){
    int start = atoi(argv[1]);
    int end = atoi(argv[2]);
    unsigned long  n = atoi(argv[3]);
    l = atoi(argv[4]);

    genVec(start, end, n);
    printf("Vectors saved.\n");

    return 1;   
}
