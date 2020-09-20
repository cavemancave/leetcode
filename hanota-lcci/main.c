#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LEN 200
typedef struct {
    int* data;
    int size;
}Stack;
int cnt = 0;
void Push(Stack* s, int d)
{
    s->data[s->size++] = d;
}
int Pop(Stack* s){
    return s->data[--s->size];
}

void hannuota(int n, Stack* A, Stack* B, Stack* C){
    if(n == 1){
        cnt ++;
        Push(C, Pop(A));
        return;
    }
    hannuota(n-1, A, C, B);
    hannuota(1, A, B, C);
    hannuota(n-1, B, A, C);
}

void hanota(int* A, int ASize, int* B, int BSize, int** C, int* CSize){
    if(ASize <= 0) return;
    Stack X,Y,Z;
    X.data = A;
    X.size = ASize;
    Y.data = (int*)malloc(sizeof(int)*MAX_LEN);
    Y.size = 0;
    int *p = (int*)malloc(sizeof(int)*MAX_LEN);
    Z.data = p;
    Z.size = 0;
    hannuota(ASize, &X, &Y, &Z);
    *C = p;
    *CSize = Z.size;
    free(Y.data);
}

int main(void){
    int A[] = {5,4,3,2,1};
    int ASize = sizeof(A)/sizeof(int);
    int *B = NULL;
    int BSize = 0;
    int *C = NULL;
    int CSize = 0;
    hanota(A, ASize, B, BSize, &C, &CSize);
    for(int i=0;i<CSize;i++){
        printf("%d,", C[i]);
    }
    free(C);
    return 0;
}