1. 暴力法
提交超时
```c 
int strStr(char * haystack, char * needle){
    if(strlen(needle)==0) return 0;
    int start = 0;
    int testLen = strlen(haystack);
    int needLen = strlen(needle);
    int j;
    for(int i=0;i<testLen;i++){
        for(j=0;j<needLen;j++){
            if(i+j==testLen) break;
            if(haystack[i+j] != needle[j]){
                break;
            }
        }
        if(j==needLen){
            return i;
        }
    }
    return -1;
}
```
2. KMP
原理入门：[字符串匹配的KMP算法- 阮一峰的网络日志 - 阮一峰的个人网站](http://www.ruanyifeng.com/blog/2013/05/Knuth%E2%80%93Morris%E2%80%93Pratt_algorithm.html)
题解先看：[宫水三叶](https://leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/)的讲解，但是第4节的代码，参考其他，因为因为宫水最后的代码在数组前面补零了，和前面的讲解不符合。
代码看：[如何更好地理解和掌握 KMP 算法? - 阮行止的回答 - 知乎](https://www.zhihu.com/question/21923021/answer/1032665486)  快速求next数组 小节
`串A和串B是相同的！B的后缀等于A的后缀！因此，使得A的k-前缀等于B的k-后缀的最大的k，其实就是串A的最长公共前后缀的长度 —— next[now-1]！`


```c

class Solution {
public:
    void getNext(int* next, const string& s) {
        int j = 0;
        next[0] = 0;
        for(int i = 1; i < s.size(); i++) {
            while (j > 0 && s[i] != s[j]) {
                j = next[j - 1];
            }
            if (s[i] == s[j]) {
                j++;
            }
            next[i] = j;
        }
    }
    int strStr(string haystack, string needle) {
        if (needle.size() == 0) {
            return 0;
        }
        int next[needle.size()];
        getNext(next, needle);
        int j = 0;
        for (int i = 0; i < haystack.size(); i++) {
            while(j > 0 && haystack[i] != needle[j]) {
                j = next[j - 1];
            }
            if (haystack[i] == needle[j]) {
                j++;
            }
            if (j == needle.size() ) {
                return (i - needle.size() + 1);
            }
        }
        return -1;
    }
};

作者：carlsun-2
链接：https://leetcode-cn.com/problems/implement-strstr/solution/dai-ma-sui-xiang-lu-kmpsuan-fa-xiang-jie-mfbs/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

```
