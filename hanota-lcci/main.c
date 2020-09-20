#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXLEN 200
typedef struct {
    int data[MAXLEN];
    int cur;
    char name;
}Stack;


void Push(Stack *stack, int d)
{
    stack->data[stack->cur++] = d;
}

int Pop(Stack *stack)
{
    return stack->data[stack->cur--];
}

int Top(Stack *stack)
{
    return stack->data[stack->cur];
}

void hannuota(int n, Stack* A, Stack* B, Stack* C)
{
    if(n == 1){
        printf("move %d form %c to %c.\n", Top(A), C->name, A->name);
        Push(C, Pop(A));
    }else{
        hannuota(n-1, A, C, B);
        hannuota(1, A, B, C);
        hannuota(n-1, B, A, C);
    }
    
}
int main()
{
    int n = 1;
    Stack A = {0};
    Stack B = {0};
    Stack C = {0};
    A.name = 'A';
    B.name = 'B';
    C.name = 'C';
    int a[10] = {0};
    a[-1] = 0; 
    hannuota(n, &A, &B, &C);

    return 0;
}