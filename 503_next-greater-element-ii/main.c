#include<stdio.h>
#include<string.h>
#include<stdlib.h>


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElements(int* nums, int numsSize, int* returnSize){
    int* res = (int *)malloc(numsSize * sizeof(int));
    memset(res, -1, numsSize*sizeof(int));
    *returnSize = numsSize;
    int stack[10001] = {0};
    int top = 0;

    for(int i=0;i<numsSize*2-1;i++){
        while(top && nums[i%numsSize]> nums[stack[top]]){
            res[stack[top]] = nums[i%numsSize];
            top--;
        }
        stack[++top] = i%numsSize; 
    }
    return res;
}

int main(void){
    int nums[] = {1,2,1};
    int resSize = 0;
    int* res = nextGreaterElements(nums, sizeof(nums)/sizeof(int), &resSize); 
    printf("%d \n", resSize);
    for(int i=0;i<resSize;i++){
        printf("%d ", res[i]);
    }
    printf("\n");
    free(res);
    return 0;
}