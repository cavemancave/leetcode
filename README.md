[toc]
# leetcode
[leetcode中国-题库](https://leetcode-cn.com/problemset/all/)  
[我的账号@cavemancave](https://leetcode-cn.com/u/cavemancave/)

# 环境搭建
[调试环境优化](00_environment/environment_prepare.md)

# 使用的基础库
## UThash
1. 安装`sudo apt install uthash-dev`  
2. 使用示例 uthashTest/main.c

## 基础函数
### qsort
```c
struct Student 
{ 
    int age, marks; 
    char name[20]; 
};
int comparator(const void *p, const void *q)  
{ 
    int l = ((struct Student *)p)->marks; 
    int r = ((struct Student *)q)->marks;  
    return (l - r); 
} 
qsort((void*)arr, arrSize, sizeof(arr[0]), comparator); 
```
## 学习教程
### labuladong
[labuladong主页](https://mp.weixin.qq.com/s/AWsL7G89RtaHyHjRPNJENA)  

[我写了套框架，把滑动窗口算法变成了默写题](https://mp.weixin.qq.com/s/ioKXTMZufDECBUwRRp3zaA)  



## 学习日志
2021-7-25 复习qsort；学习滑动窗口
[滑动窗口算法解决子串问题](https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247484504&idx=1&sn=5ecbab87e42033cc0a62b635cc436977&chksm=9bd7fa50aca07346a3ffa6be6fccc445968c162af9532fa9c6304eaab2e3a1b79a4bbe758c0a&scene=21#wechat_redirect)

# 动态规划
## 理论和示例


## 相关题目
62 不同路径  


## 深度优先搜索
书上和其他博客的区别是，书上图已经确定了，其他博客给的是图还没出来时，通过选择列表来生成图，回溯时，选择列表要还原。


深度优先遍历图和深度优先遍历树相似，唯一区别是：图包含环，需要使用一个数组保存节点是否被访问过
```c
void DFS_Util(){
  bool used[N] = {0};
  for(v =0;v<N;v++){
    if(!used[v]){
      DFS(G, v);
    }
  }
}
void DFS(G, v){
  used[v] = 1;
  visitFun(v);
  for(w=nextAdj(G, v)){
    if(!used[w]){
      DFS(G, w);
    }
  }
}
```
[回溯算法详解（修订版）](https://mp.weixin.qq.com/s/nMUHqvwzG2LmWA9jMIHwQQ)
[leetcode刷题最强指南（版本1.0）](https://mp.weixin.qq.com/s?__biz=MzUxNjY5NTYxNA==&mid=2247486267&idx=1&sn=614e6799fcbda82c268bf28ff6fe5b22&chksm=f9a2386aced5b17cc3edad231b6001b3319a2cb6fa6ba7ee37673fec51624555f161a9688ee3&scene=132#wechat_redirect)
2.2 那么深度优先就可以克服这个缺点，因为每次搜的过程，每一层只需维护一个节点。(为了找到相邻节点，也需要维护同层节点才对啊)

24点
只有3层，但是每层节点数很多，所以DFS要比BFS快

简单马周游跟马周游
启发式搜索的算法，例如A*算法等

原博客地址
https://blog.csdn.net/gtgym321



回溯算法的框架：
result=[]
def backtrack(路径，选择列表):
  if 满足结束条件：
    result.add(路径)
    return
  for 选择 in 选择列表：
    做选择
    backtrack(路径，选择列表)
    撤销选择
46, 47,



## 双指针，滑动窗口
[leetCode之双指针遍历/滑动窗口](https://www.jianshu.com/p/a938076d8bab)  
3. 无重复字符的最长子串  
11. 盛最多水的容器  
15. 三数之和  
16. 最接近的三数之和  
26. 删除排序数组中的重复项  
75. 颜色分类  
209. 长度最小的子数组  
80. 删除排序数组中的重复项 II  

## 九阴真经第一式 单调栈
[84. 柱状图中的最大矩形](https://leetcode-cn.com/problems/largest-rectangle-in-histogram/)  
[739. 每日温度]()  
503 下一个更大元素[II][1]  
85 最大矩形  
42 接雨水（困难，性能敏感）  
901 股票价格跨度  
239 滑动窗口最大值（困难，O(n))  




单调栈	https://leetcode-cn.com/problems/next-greater-element-ii/
单调栈	https://leetcode-cn.com/problems/online-stock-span/
滑动窗口	https://leetcode-cn.com/problems/max-consecutive-ones-iii/
滑动窗口	https://leetcode-cn.com/problems/minimum-size-subarray-sum/
bfs	https://leetcode-cn.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
bfs	https://leetcode-cn.com/problems/surrounded-regions/
dfs	https://leetcode-cn.com/problems/shortest-bridge/solution/
回溯算法	https://leetcode-cn.com/problems/letter-combinations-of-a-phone-number/
差分	https://leetcode-cn.com/problems/car-pooling/
排序	https://leetcode-cn.com/problems/maximum-number-of-events-that-can-be-attended/
设计+uthash	https://leetcode-cn.com/problems/design-authentication-manager/
设计+uthash	https://leetcode-cn.com/problems/design-underground-system/
![image](https://user-images.githubusercontent.com/19219206/130917561-491337b3-a326-4694-b300-88fefb8916d8.png)






## 	

[1]: http://slashdot.org

## 参考
[ref1]:[OI Wiki](https://oi-wiki.org/tools/wsl/)


[I'm an inline-style link](https://www.google.com)

[I'm an inline-style link with title](https://www.google.com "Google's Homepage")

[I'm a reference-style link][Arbitrary case-insensitive reference text]

[I'm a relative reference to a repository file](../blob/master/LICENSE)

[You can use numbers for reference-style link definitions][1]

Or leave it empty and use the [link text itself].

URLs and URLs in angle brackets will automatically get turned into links. 
http://www.example.com or <http://www.example.com> and sometimes 
example.com (but not on Github, for example).

Some text to show that the reference links can follow later.

[arbitrary case-insensitive reference text]: https://www.mozilla.org
[1]: http://slashdot.org
[link text itself]: http://www.reddit.com
