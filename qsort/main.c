#include<stdio.h>
#include<stdlib.h>

int values[] = { 88, 56, 100, 2, 25 };

int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int main(){
    int n = sizeof(values)/sizeof(int);
    qsort(values, n, sizeof(int), comp);
    for(int i=0;i<n;i++){
        printf("%d ", values[i]);
    }
    printf("\n");
    return 0;
}