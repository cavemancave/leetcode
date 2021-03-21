#include<stdio.h>
#include<stdlib.h>
#include<math.h>


int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int threeSumClosest(int* nums, int numsSize, int target){
    if(nums == NULL || numsSize < 3) return -1;
    qsort(nums,numsSize, sizeof(int), comp);
    int diffMax = __INT_MAX__;
    int res = 0;
    for(int i=0;i<numsSize;i++){
        if(i>0 && nums[i] == nums[i-1]) {continue;}
        int L  = i+1;
        int R = numsSize -1;
        while(L<R){
            int sums = nums[i] + nums[L] + nums[R];
            if(sums < target){
                while(L<R && nums[L] == nums[L+1]) L++;
                L++;
            }else if(sums > target){
                while(L<R && nums[R] == nums[R-1]) R--;
                R--;
            }else{
                return sums;
            }
            int diff = abs(sums - target);
            if(diff < diffMax){
                diffMax = diff;
                res = sums;
            }

        }
    }
    return res;
}

int main(void){
    int nums[]={0,1,1,5,5};
    int numsSize = sizeof(nums)/sizeof(int);
    int target = 3;
    int res = threeSumClosest(nums, numsSize, target);
    printf("ans:%d\n",res);
    return 0;
}