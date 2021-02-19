#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

//https://leetcode-cn.com/problems/permutations/solution/hui-su-suan-fa-python-dai-ma-java-dai-ma-by-liweiw/
#define LEN 2000
int resNum=0;
int pathI = 0;
int len = 0;
void AddResult(int **result, int* path){
    int* tmpNums=(int*)malloc(len*sizeof(int));
    memcpy(tmpNums, path, len*sizeof(int));
    result[resNum++] = tmpNums;
}
void dfs(int* nums, int depth, int* path, bool* used, int** res){
    if(depth == len){
        AddResult(res, path);
        return;
    }

    for(int i=0;i<len;i++){
        if(!used[i]){
            used[i] = 1;
            path[pathI++] = nums[i];

            dfs(nums, depth +1, path, used, res);

            pathI--;
            used[i] = 0;
        }
    }
}
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    resNum = 0;
    pathI = 0;
    len = numsSize;
    int path[LEN] = {0};
    int* res[LEN]= {0};
    bool used[LEN] = {0};

    dfs(nums, 0, path, used, res);
    
    int** result = (int**)malloc(LEN*sizeof(int*));
    memcpy(result, res, resNum*sizeof(int*));

    (*returnColumnSizes) = (int*)malloc(resNum*sizeof(int));
    for(int i=0;i<resNum;i++){
        (*returnColumnSizes)[i] = numsSize;
    }
    *returnSize = resNum;
    return result;
}


/*
输入: [1,2,3]
输出:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

// int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){

int main(void){
    int in[3] = {1,2,3};
    int returnSize = 0;
    int* returnColSize;
    int** result;
    result = permute(in, 3, &returnSize, &returnColSize);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColSize[i];j++){
            printf("%d, ", result[i][j]);
        }
        free(result[i]);
        printf("\n");
    }
    free(result);
    free(returnColSize);
}