#include "io.h"
#include "sort.h"


unsigned int l = 10; //have to be consistent with the genVec


int main(int argc, char** argv){
    printf("Please specify the input file (default = inVec.txt): "); 
    char* fileIN = readFname("inVec.txt");
    printf("Please specify the output file (default = outVec.txt): ");
    char* fileOUT = readFname("outVec.txt");

    printf("Input file: %s\n", fileIN);
    printf("Output file: %s\n", fileOUT);

    char* s = readFile(fileIN);
    int row = 0;
    char** A = S2A(s, &row);
    int** arr = A2I(A, row);
    
    int P[row];
    for (int i = 0; i < row; i++)
        P[i] = i;
    for (int i = l-1; i >= 0; i--)
        countSort(arr, row, i, P);

    writeVec(A, row, P, fileOUT);

    return 1;
}
