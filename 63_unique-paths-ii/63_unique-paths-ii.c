#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void PrintMatrix(int **a, int m, int n){
    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}
int GetPositive(int n){
    return (n>0)?n:0;
}
int Max(a,b){
    return (a>b)?a:b;
}
int uniquePathsWithObstacles(int** obstacleGrid, int obstacleGridSize, int* obstacleGridColSize){
    int m = obstacleGridSize;
    int n = obstacleGridColSize[0];
    if(m<1 || n<1) return 0;

    for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(obstacleGrid[i][j] == 1){
                obstacleGrid[i][j] = -1;
            }
        }
    }

    for(int i=0;i<m;i++){
        obstacleGrid[i][0] = (obstacleGrid[i][0]<0)?-1:1;
    }
    for(int i=0;i<m;i++){
        obstacleGrid[0][i] = (obstacleGrid[0][i]<0)?-1:1;
    }
    obstacleGrid[0][0] = 0;
   // PrintMatrix(obstacleGrid,3,3);

    for(int i=1;i<m;i++){
        for(int j=1;j<n;j++){
            if(obstacleGrid[i][j] < 0){continue;}
            obstacleGrid[i][j] = GetPositive(obstacleGrid[i-1][j]) + 
                GetPositive(obstacleGrid[i][j-1]);
            
        }
    }
   // PrintMatrix(obstacleGrid,3,3);
    return obstacleGrid[m-1][n-1];
}

#define MAXN 100
struct TestData{
    int grid[MAXN][MAXN];
    int m;
    int n;
    int ret;
};

int main() {
    struct TestData data[] = {
        { //input data
            { //grid
                {0,0,0},
                {0,1,0},
                {0,0,0},
            },
            3,  //m
            3,  //n
            2,  //ret
        },
    };
    int obstacleGridColSize[MAXN] = {0};
    int len = sizeof(data)/sizeof(struct TestData);
    for(int i=0;i<len;i++){
        int m = data[i].m;
        int n = data[i].n;
        int** obstacleGrid = (int **)malloc(m*sizeof(int*));
        for(int j=0;j<m;j++){
            obstacleGrid[j] = &data[i].grid[j][0];
            obstacleGridColSize[j] = n;
        }
        int ret = uniquePathsWithObstacles(obstacleGrid, m, obstacleGridColSize);
        if(ret != data[i].ret){
            printf("failed %dth\nret %d\nexpect %d\n", i, ret, data[i].ret);
        }
        free(obstacleGrid);
    }

    printf("end.");
    return 0;
}
