#include <stdio.h>
#include <stdlib.h>

void AddRes(int** res, int* returnSize, int a, int b, int c){
    int* resLine = (int*)malloc(3*sizeof(int));
    resLine[0]  = a;
    resLine[1]  = b;
    resLine[2]  = c;
    res[*returnSize] = resLine;
    *returnSize = *returnSize + 1;
}
int** MakeRes(int** res, int *returnSize, int **returnColumnSizes){
    if(*returnSize == 0){
        free(res);
        return NULL;
    }
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for(int i=0;i<*returnSize;i++) (*returnColumnSizes)[i] = 3;
    return res;
}
int comp(const void* a, const void* b){
    return *(int*)a - *(int*)b;
}
int **threeSum(int *nums, int numsSize, int *returnSize, int **returnColumnSizes){
    if(nums == NULL || numsSize <3 ){
        *returnSize = 0;
        return NULL;
    }
    int N = numsSize;
    qsort(nums, N, sizeof(int), comp);
    *returnSize = 0;
    int** res = (int**)malloc(100000*sizeof(int*));
    for(int i=0;i<N;i++){
        if(nums[i]>0){
            return MakeRes(res, returnSize, returnColumnSizes);
        }
        if(i>0 && nums[i]== nums[i-1]){
            continue;
        } 
        int L= i+1;
        int R = N -1;
        while(L<R){
            int sum = nums[i] + nums[L] + nums[R];
            if(sum == 0){
                AddRes(res, returnSize, nums[i], nums[L], nums[R]);
                while(L<R && nums[L]==nums[L+1] ) L++;
                while(L<R && nums[R]==nums[R-1]) R--;
                L++;
                R--;
            }else if(sum < 0){
                while(L<R && nums[L]==nums[L+1] ) L++;
                L++;
            }else{
                while(L<R && nums[R]==nums[R-1]) R--;
                R--;
            }
        }
    }
    return MakeRes(res, returnSize, returnColumnSizes);
}
int main()
{

    int nums[] = {0,0,0,5};
    int numsSize = sizeof(nums) / sizeof(int);
    int returnSize = 0;
    int *returnColumnSizes;
    int **res;
    res = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);
    if (numsSize == 0)
        return 1;
    for (int i = 0; i < returnSize; i++)
    {
        for (int j = 0; j < returnColumnSizes[i]; j++)
        {
            printf("%d ", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);

    return 0;
}

/*
1. 有一个超大输入，有8K多个数字，结果数组需要申请到10000；
2. 返回为空时，要把*returnSize置为0，free(res)，returnColumnSizes也是NULL，否则会出现：
AddressSanitizer:DEADLYSIGNAL
*/