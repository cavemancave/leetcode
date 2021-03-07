#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int N = 0;
int resNum = 0;
char *letterMap[] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

void AddRes(char** res, char* str){
    char* copy = (char*)malloc((N+1)*sizeof(char));
    memcpy(copy, str, (N+1)*sizeof(char));
    copy[N] = '\0';
    res[resNum++]=copy;
}
void backtrace(char** res, char* line, char* digits, int index){
    if(index == N){
        AddRes(res, line);
        return;
    }
    
    char* map = letterMap[digits[index] - '0'];
    for(int i=0;i<strlen(map);i++){
        line[index++] = map[i];
        backtrace(res, line, digits, index);
        index--;
    }
}

char ** letterCombinations(char * digits, int* returnSize){
    N = strlen(digits);
    if(N==0){
        *returnSize = 0;
        return NULL;
    }
    resNum = 0;
    char** result = (char**)malloc(10000*sizeof(char*));
    char* line = (char*)malloc((N+1)*sizeof(char));
    backtrace(result, line, digits, 0);
    *returnSize = resNum;
    free(line);
    return result;
}

int main(int argc, char*argv[]){
    char** result;
    int returnSize;
    char* digits = "23";
    result = letterCombinations(digits, &returnSize);

    for(int i=0;i<returnSize;i++){
        printf("%s ", result[i]);
        free(result[i]);
    }
    free(result);
    return 0;
}



/*
input [[""]]
output [] NULL
*/