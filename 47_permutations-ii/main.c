#include<stdlib.h>
#include<stdio.h>
#include<string.h>

int resNum = 0;
int len = 0;
int pathLen = 0;
void addRes(int** res, int* path, int** returnColumnSizes){
    int* pathTmp = (int*)malloc(len*sizeof(int));
    memcpy(pathTmp, path, len*sizeof(int));
    res[resNum] = pathTmp;
    (*returnColumnSizes)[resNum] = len;
    resNum++;
}

void dfs(int* nums, int* path, int* used, int** res, int** returnColumnSizes){
    if(pathLen == len){
        addRes(res, path, returnColumnSizes);
    }

    for(int i=0;i<len;i++){
        if((i>0) && (nums[i]==nums[i-1]) && (used[i-1]==0)){

        }else{
            if(used[i]==0){
                path[pathLen++] = nums[i];
                used[i] = 1;

                dfs(nums, path, used, res, returnColumnSizes);

                used[i] = 0;
                pathLen--;
            }
        }
        

    }
}

int comp(const void* p, const void* q){
    int m= *((int*)p);
    int n=*((int*)q);
    return m-n;
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permuteUnique(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

    qsort(nums, numsSize, sizeof(int), comp);
    len = numsSize;
    resNum = 0;
    int** res = (int**)malloc(1000 * sizeof(int*));
    (*returnColumnSizes) = (int*)malloc(1000 * sizeof(int));
    int* used = (int*)malloc(len* sizeof(int));
    memset(used, 0, len* sizeof(int));
    int* path = (int*)malloc(len* sizeof(int));
    pathLen = 0;
    dfs(nums, path, used, res, returnColumnSizes);

    *returnSize = resNum;
    return res;
}

#ifdef __XGH_TEST__
int main(void){
    int nums[] = {1,2,3};
    int returnSize = 0;
    int* returnColumnSizes = NULL;
    int** res;

    res = permuteUnique(nums, 3, &returnSize, &returnColumnSizes);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];j++){
            printf("%d,", res[i][j]);
        }
        printf("\n");
        free(res[i]);
    }
    free(res);
    free(returnColumnSizes);
    return 0;
}
#endif

//要先排序
//本次的数和上次一致，并且上次已释放
//(i>0) && (nums[i]==nums[i-1]) && (used[i-1]==0)
