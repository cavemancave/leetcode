#include<stdio.h>
#include <stdlib.h>

int arr[] = {3,1,4,1,5,9,2,6};
int comp(const void* a, const void *b){
    return *(int*)a - *(int*)b;
}
int main(void){
    int arrLen = sizeof(arr)/sizeof(int);
    qsort(arr, arrLen, sizeof(int), comp);
    for(int i=0;i<(arrLen);i++){
        printf("%d,", arr[i]);
    }
    return 0;
}