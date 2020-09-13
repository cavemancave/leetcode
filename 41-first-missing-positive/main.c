
#include<stdio.h>
#include<stdlib.h>
void swap(int *a, int*b)
{
    int c = *a;
    *a = *b;
    *b = c;
}
int firstMissingPositive(int* nums, int numsSize){

    if(numsSize <= 0) return 1;
    for(int i=0;i<numsSize;i++){
        while(nums[i]>0 && nums[i]<=numsSize &&
              nums[i] != (i+1) &&
              nums[i] != nums[nums[i]-1]){
            swap(nums+i, nums + nums[i] - 1);
        }
    }
    for(int i=0;i<numsSize;i++){
        if(nums[i] != (i+1)){
            return i+1;
        }
    }
    return numsSize+1;

}

void main(void)
{
    int array[] = {-1,4,2,1,9,10};
    int ret = firstMissingPositive(array, sizeof(array)/sizeof(int));
    printf("%d", ret);
}