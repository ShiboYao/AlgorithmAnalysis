#include "io.h"
#include <string.h>


int main(){
    long n[] = {10000, 100000, 1000000};
    int size = sizeof(n)/sizeof(long);
    for (int i = 0; i < size; i++){
        char* fname = strcat(itoa(n[i]), ".txt");
        genArr(n[i], fname);
    }

    return 1;
}
