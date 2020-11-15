
#include<stdio.h>
#include<string.h>

int compress(char* chars, int charsSize){
    char buf[100] = {0};
    int write = 0;
    for(int read = 0, anchor = 0; read < charsSize; anchor = read){
        while(read < charsSize && chars[read] == chars[anchor]){
            read++;
        }
        chars[write++] = chars[anchor];
        if(read - anchor <= 1){
            continue;
        }
        int cnt = sprintf(buf, "%d", read - anchor);
        for(int i=0;i<cnt;i++){
            chars[write++] = buf[i];
        }
    }
    return write;
}

int main(void){

    char a[] = {"aaaaaaaaaa"};
    int cnt = compress(a, sizeof(a) - 1);
    printf("%d\n", cnt);
    for(int i=0; i< cnt;i++){
        printf("%c ", a[i]);
    }
    printf("\n %s", a);
    return 0;
}


// https://leetcode-cn.com/problems/string-compression/solution/cyu-yan-jie-jue-shuang-zhi-zhen-fa-by-xuan-21-2/
/*
int compress(char* chars, int charsSize){
    int write = 0;
    char buf[1000];
    for(int read=0, anchor=0;read<charsSize;anchor=read)
    {
        while(read<charsSize&&chars[read]==chars[anchor])
            read++;
        chars[write++] = chars[anchor];
        if(read-anchor==1)
            continue;
        sprintf(buf,"%d",read-anchor);
        for(int i=0;i<strlen(buf);i++)
            chars[write++] = buf[i];
    }
    return write;
}
*/