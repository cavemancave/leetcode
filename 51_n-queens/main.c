#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int N = 0;
int mapListLen = 0;

char** NewMap(){
    char** map = (char**)malloc(N*sizeof(char*));
    for(int i=0;i<N;i++){
        map[i] = (char*)malloc((N+1)*sizeof(char));
        for(int j=0;j<N;j++){
            map[i][j]='.';
        }
        map[i][N] = 0;
    }
    return map;
}

char** CopyMap(char** srcMap){
    char** newMap = NewMap();
    for(int i=0;i<N;i++){
        memcpy(newMap[i], srcMap[i], N*sizeof(char));
    }
    return newMap;
}

void AddMapList(char*** mapList, char** map){
    char** newMap = CopyMap(map);
    mapList[mapListLen++] = newMap;
}

void DelMap(char** map){

    for(int i=0;i<N;i++){
        free(map[i]);
    }
    free(map);
}

int IsValid(char** map, int row, int col){
    int tmp;
    for(int i=row-1;i>=0;i--){
        
        if(map[i][col] == 'Q') {
            return 0;
        }
        tmp = col-row+i;
        if((tmp >= 0) && (tmp<N) && (map[i][tmp] == 'Q')) {
            return 0;
        }
        tmp = col-i+row;
        if((tmp >= 0) && (tmp<N) && (map[i][tmp] == 'Q')) {
            return 0;
        }
    }
    return 1;
}
void DFS(char*** mapList, char** map, int row){
    if(row == N){
        AddMapList(mapList, map);
        return;
    }

    for(int i=0;i<N;i++){
        if(IsValid(map, row, i)){
            map[row][i] = 'Q';
            DFS(mapList, map, row+1);
            map[row][i] = '.';
        }
    }

}

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char *** solveNQueens(int n, int* returnSize, int** returnColumnSizes){
    N = n;
    mapListLen = 0;
    char*** mapList = (char***)malloc(1000*sizeof(char**));
    char** map = NewMap();
    DFS(mapList, map, 0);
    *returnSize = mapListLen;
    *returnColumnSizes = (int*)malloc(*returnSize * sizeof(int));
    for(int i=0;i<*returnSize;i++){
        (*returnColumnSizes)[i] = N;
    }
    DelMap(map);
    return mapList; 
}

#ifdef __XGH_TEST__
int main(int argc, char*argv[]){
    char ***result;
    int returnSize;
    int* returnColumnSizes;
    int n = 3;
    if(argc > 1){
        n = atoi(argv[1]);
        printf("size:%d \n", n);
    }

    result = solveNQueens(n, &returnSize, &returnColumnSizes);
    for(int i=0;i<returnSize;i++){
        for(int j=0;j<returnColumnSizes[i];j++){
            printf("%s\n",result[i][j]);
            free(result[i][j]);
            printf("\n");
        }
        free(result[i]);
        printf("===========\n");
    }
    free(returnColumnSizes);
    free(result);
    return 0;
}
#endif


/*
用例中最后使用的printf(%s), 所以要多申请以为存储0；

*/