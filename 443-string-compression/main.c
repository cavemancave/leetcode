#include<stdio.h>
#include<string.h>

char* writeCnt(char* start, int cnt){
    int test[100] = {0};
    int i = 0;
    int a = cnt % 10;
    do{
        test[i++] = cnt % 10 + '0';
        cnt /= 10;
    }while(cnt != 0);

    while(i--){
        *start++ = test[i];
    }
    return start;
}

int compress(char* chars, int charsSize){
    if(charsSize <= 1) return 1;
    char p = chars[0];
    char ch= chars[0];
    char cnt = 1;
    char *out = chars;
    out++;
    for(int i=1;i<charsSize;i++){
        p = chars[i];
        if(ch != p){
            if(cnt > 1){
                out = writeCnt(out, cnt);
            }
            *out = p;
            out++;
            cnt = 1;
            ch = p;
        }else{
            cnt++;
        }
    }

    if(cnt > 1){
        out = writeCnt(out, cnt);
    }
    return out - chars;
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
