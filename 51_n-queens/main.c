#include<stdio.h>
#include<stdlib.h>
#include<string.h>


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){

}

int main(void){
    char ***result;
    int returnSize;
    int* returnColumnSizes;

    result = solveNQueens(2, &returnSize, &returnColumnSizes);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];j++){
            for(int k=0;k<returnColumnSizes[i];k++){
            printf("%s ", result[i][j][k]);
        }
        printf("\n");
    }
    return 0;
}