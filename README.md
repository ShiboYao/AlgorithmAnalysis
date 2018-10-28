# Requirements
Original environment is Ubuntu Linux. 

Program written in C. 

gcc compiler. 


#1. Sorting Algorithm Comparison
Implement MergeSort, HeapSort and QuickSort, and analyze their time complexity and efficiency by looking at the operations made and time taken by each algorithm.

## File Description
sort.h: sorting algorithm implementation. 

io.h: input/output control. 

genVec.c: program to generate data. 

driver.c: run sorting on the generated data. 

setVec.txt: settings for generating data. 

setSort.txt: settings for sorting. 

tabulate.c: automaticly generate data and run sorting based on the two setting files. 


## Usage
### For simple comparison:

gcc -o genVec genVec.c

gcc -o driver driver.c

./genVec START END n l (e.g. ./genVec 0 99 1024 3, which means generate 1024 vectors of length 3 with integer values ranging from 0 to 99). See more info within genVec.c

./driver sortAlg data writeOpt (e.g. ./driver M o w, which means run MergeSort on original random data and write sorted data to file). See more info within driver.c


### For somprehensive comparison and tabulating result:

gcc -o tabulate tabulate.c

./tabulate settings\_for\_vector settings\_for\_sort (e.g ./tabulate setVec.txt setSort.txt)

(optional) append "|&tee result.txt" to save terminal output to file (running time and comparisons made)

If found data.txt, that is the original random data; if found aadt.txt, that is the sorted data; if found tdaa.txt, that is the reversed data. 


#2. Selection Algorithm 
Deterministic pivot based on median of median, quick select Kth smallest elements in an array. 

Implemented by Shibo Yao, espoyao(at)gmail(dot)com
