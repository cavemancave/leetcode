#include<stdlib.h>
#include<stdio.h>

void swap(int *a, int* b){
    int t = *a;
    *a  = *b;
    *b = t;
}
void sortColors(int* nums, int numsSize){
    if(numsSize<2) return;

    int i=0;
    int j = numsSize -1;
    int k =0;
    while(k<=j){
        if(nums[k]==0){
            swap(nums+i, nums+k);
            i++;
            k++;
        }else if(nums[k] == 2){
            swap(nums+k, nums+j);
            j--;
        }else{
            k++;
        } 
    }
}
int main(void){
    //int nums[] = {2,0,2,1,1,0};
    int nums[] = {2,0,1};
    int numsSize = sizeof(nums)/sizeof(int);
    sortColors(nums, numsSize);
    for(int i=0;i< numsSize;i++){
        printf("%d ", nums[i]);
    }
    printf("\n");
    return 0;
}

/*
注意nums==0时，i和K要同时++；要不k会小于i；

00001111111122
    i
           j
        k
*/