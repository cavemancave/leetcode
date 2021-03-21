#include<stdio.h>
#include<stdlib.h>

int removeDuplicates(int* nums, int numsSize){
    if(nums == NULL || numsSize==0){
        return numsSize;
    }
    int i=0;
    for(int j=0;j<numsSize;j++){
        if(nums[i]!= nums[j]){
            nums[++i] = nums[j];
        }
    }
    return i+1;
}
int main(void){
    int nums[]={0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums)/sizeof(int);
    int res = removeDuplicates(nums, numsSize);
    printf("%d \n", res);
    for(int i=0;i<res;i++){
        printf("%d ", nums[i]);
    }
    return 0;
}

/*
1.输入有空数组的情况


*/