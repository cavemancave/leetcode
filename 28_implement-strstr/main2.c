int strStr(char * haystack, char * needle){
    if(strlen(needle)==0) return 0;
    int next[102400] = {0};
    int x = 1;
    int now = 0;
 
    int lenp = strlen(needle);
    while (x<lenp){
        if(needle[x] == needle[now]){
            now += 1;
            next[x] = now; 
            x += 1;
        }else if(now){
            now = next[now -1 ];
        }else{
            next[x] = 0;
            x += 1;
        }
    }
    for(int i=0;i<lenp;i++)
        printf("%d ", next[i]);
    int lens = strlen(haystack);
    x = 0;
    now  = 0;
    while (x < lens){
        if(haystack[x] == needle[now]){
            x++;
            now++;
        }else if(now){
            now = next[now -1];
        }else{
            x++;
        }
        if (now == lenp){
            return x - now ;
        }
    }
    return -1;
}