#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N = 0;
int K = 0;
int resultCnt = 0;
int colCnt = 0;
void AddResult(int** result, int* col){
    int *copy = (int*)malloc(sizeof(int)*K);
    memcpy(copy, col, sizeof(int)*K);
    result[resultCnt++] = copy;
}

void backtrace(int**result, int* col, int start){
    if(colCnt == K){
        AddResult(result, col);
        return;
    }

    for(int i=start;i<N;i++){
        col[colCnt++] = i+1;
        backtrace(result, col, i+1);
        colCnt--;
    }
}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    N = n;
    K = k;
    resultCnt = 0;
    colCnt = 0;
    int **result = (int**)malloc(10000*sizeof(int*));
    int *col = (int*)malloc(K*sizeof(int));
    backtrace(result, col, 0);
    
    free(col);

    *returnSize = resultCnt;
    *returnColumnSizes = (int*)malloc(resultCnt*sizeof(int));
    for(int i=0;i<resultCnt;i++){
        (*returnColumnSizes)[i] = K;
    }


    return result;
}

#define __XGH_TEST__
#ifdef __XGH_TEST__
int main(int argc, char*argv[]){
    int **result;
    int returnSize;
    int* returnColumnSizes;
    int n = 4;
    int k = 2;
    if(argc > 1){
        n = atoi(argv[1]);
        k = atoi(argv[2]);
        printf("size:%d \n", n);
    }

    result = combine(n, k, &returnSize, &returnColumnSizes);
    printf("resultSize: %d.\n", returnSize);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];j++){
            printf("%d,",result[i][j]);
        }
        printf("\n");
        free(result[i]);
    }
    free(returnColumnSizes);
    free(result);
    return 0;
}
#endif


/*
用例中最后使用的printf(%s), 所以要多申请以为存储0；

*/