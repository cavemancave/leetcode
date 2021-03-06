# leetcode

# 环境搭建
[调试环境优化](00_environment/environment_prepare.md)

# UThash
`sudo apt install uthash-dev`
uthashTest/main.c

# 基础函数
qsort()
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
84 柱状图中的最大矩形
739 每日温度
503 下一个更大元素II
85 最大矩形
42 接雨水（困难，性能敏感）
901 股票价格跨度
239 滑动窗口最大值（困难，O(n))