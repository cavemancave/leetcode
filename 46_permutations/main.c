#include<stdio.h>
#include<stdlib.h>
#include<string.h>



int* res[100]= {0};
int resNum=0;
typedef struct {
    int* data;
    int len;
}myVector;

int* input = NULL;
int inputNum = 0;
void backtrack(myVector path, int* selectList){

    if (path.len == inputNum){
        int* resultRow = (int*)malloc(inputNum*sizeof(int));
        memcpy(path.data, resultRow, inputNum*sizeof(int));
        res[resNum++] = resultRow;
        return;
    }
         
    for(int i=0;i<inputNum;i++){
        if(selectList[i] == 1)
            continue;
        selectList[i] = 1;
        path.data[path.len++] = input[i];
        
        backtrack(path,selectList);

        selectList[i] = 0;
        path.len--;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    input = nums;
    inputNum = numsSize;

    myVector path = {0};
    path.data = (int*)malloc(numsSize*sizeof(int));
    int* selectList = (int*)malloc(numsSize*sizeof(int));
    memset(selectList, 0, numsSize*sizeof(int));
    backtrack(path, selectList);

    int** result = (int**)malloc(resNum*sizeof(int*));
    int* resultColSize = (int*)malloc(resNum*sizeof(int));
    for(int i=0;i<numsSize;i++){
        result[i] = res[i];
        resultColSize[i] = numsSize;
    }
    *returnColumnSizes = resultColSize;
    *returnSize = resNum;
    free(selectList);
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