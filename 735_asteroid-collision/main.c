#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int Collision(int a, int b)
{
    return (a<0 && b>0);
}
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize){
    if(asteroidsSize == 0){
        *returnSize = 0;
        return 0;
    }
    int stack[100001] = {0};
    int top = 0;
    stack[top++] = 0;
    for(int i=1;i<asteroidsSize;i++){
        int addStack = 1;
        while(top){
            int a = asteroids[i];
            int b = asteroids[stack[top-1]];
            if(!Collision(a, b)){
                break;
            }
            if(abs(a) < abs(b)){
                addStack = 0;
                break;
            }else if(abs(a) == abs(b)){
                addStack = 0;
                top--;
                break;
            }
            top--;
        }
        if(addStack){
            stack[top++] = i;
        }
    }
    if(top == 0){
        *returnSize = 0;
        return 0;
    }
    int *res = (int*)malloc(top *sizeof(int));
    for(int i=0;i<top;i++){
        res[i] = asteroids[stack[i]];
    }
    *returnSize = top;
    return res;
}
int test1(int *input, int inputSize)
{
    int returnSize = 0;
    int *res = asteroidCollision(input, inputSize, &returnSize);
    printf("%d\n", returnSize);
    for(int i=0;i<returnSize;i++){
        printf("%d ", res[i]);
    }
    if(res){
        free(res);
    }
    printf("\n");
    return 0;
}
int main(void)
{
    
    int input[] = {5,10,-5};
    test1(input, sizeof(input)/sizeof(int));
    int input2[] = {8,-8};
    test1(input2, sizeof(input2)/sizeof(int));
    
    int input3[] = {10,2,-5};
    test1(input3, sizeof(input3)/sizeof(int));
    int input4[] = {-2,-1,1,2};
    test1(input4, sizeof(input4)/sizeof(int));
    return 0;
}