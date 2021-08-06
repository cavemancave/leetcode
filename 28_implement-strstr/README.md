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
题解先看：[简单题学 KMP 算法- 宫水三叶 - 力扣](https://leetcode-cn.com/problems/implement-strstr/solution/shua-chuan-lc-shuang-bai-po-su-jie-fa-km-tb86/)的讲解，但是第4节的代码，参考其他，因为因为宫水最后的代码在数组前面补零了，和前面的讲解不符合。
代码看：[如何更好地理解和掌握 KMP 算法? - 阮行止的回答 - 知乎](https://www.zhihu.com/question/21923021/answer/1032665486)  快速求next数组 小节
`串A和串B是相同的！B的后缀等于A的后缀！因此，使得A的k-前缀等于B的k-后缀的最大的k，其实就是串A的最长公共前后缀的长度 —— next[now-1]！`


```python
p = "ABCDEFG"
next = []
def buildNext():
    next.append(0)    # next[0] 必然是0
    x = 1             # 因此从next[1]开始求
    now = 0
    while x < len(p):
        if p[now] == p[x]:    # 如果p[now]==p[x]，则可以向右扩展一位
            now += 1
            x += 1
            next.append(now)
        elif now:
            now = next[now-1]   # 缩小now，改成next[now-1]
        else:
            next.append(0)    # now已经为0，无法再缩，故next[x]=0
            x += 1

```
