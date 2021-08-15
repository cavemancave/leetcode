#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int strStr(char * haystack, char * needle){
    int Tlen = strlen(needle);
    if(Tlen==0) return 0;
    int Slen = strlen(haystack);
    int *next = (int*)malloc(Tlen*sizeof(int));

    int i = 1;
    int cur = 0;
    next[0] = 0;
    while(i<Tlen){
        if(needle[i] == needle[cur]){
            cur++;
            next[i] = cur;
            i++;
        }else if(cur){
            cur = next[cur -1];
        }else{
            next[i] = 0;
            i++;
        }
    }
    for(int j=0;j<Tlen;j++) {
        printf("%d,", next[j]);
    }
    
    i =0;
    cur = 0;
    while(i<Slen){
        if(haystack[i] == needle[cur]){
            i++;
            cur++;
        }else if(cur){
            cur = next[cur - 1];
        }else{
            i++;
        }
        if(cur == Tlen){
            free(next);
            return i-Tlen;
        }
    }
    free(next);
    return -1;
}

int main(void){
    char S[] = "mississippi";
    char T[] = "issip";
    int find = 4;
    int ret;
    printf("hellot strstr\n");
    ret = strStr(S, T);
    if(ret != find){
        printf("error, ret:%d", ret);
    }
    return 0;
}
