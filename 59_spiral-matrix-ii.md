
# 思路
- 遵循左闭右开
- 列举2次找规律
- 如果是奇数，要填充中心

# 找规律
用excel画一下遍历路径和下标  
![image](https://user-images.githubusercontent.com/19219206/194744731-acdfb977-1dda-47d2-bb70-1876d10b5aa9.png)

```txt
loop 1 
0, 0     ->  0, n-2   
0, n-1   ->  n-2, n-1  
n-1, n-1 ->  n-1, 1
0, n-1   ->  0, 1  

loop 2  
1, 1     ->  1, n-3  
1, n-2   ->  n-3, n-2  
n-2, n-2 ->  n-2,2
n-2, 1   ->  n-4, 2

loop i  
i-1, i-1    -> i-1, n-1-i  
i-1, n-i -> n-1-i, n-i
n-i, n-i -> n-i, i
i-1, n-i -> i-1, i

```txt
# 代码

```


```
