
# 思路
- 遵循左闭右开
- 列举2次找规律
- 如果是奇数，要填充中心

# 找规律
用excel画一下遍历路径和行列下标  
![image](https://user-images.githubusercontent.com/19219206/194744731-acdfb977-1dda-47d2-bb70-1876d10b5aa9.png)

```txt
行，列
loop 1 
0, 0     ->  0, n-2   
0, n-1   ->  n-2, n-1  
n-1, n-1 ->  n-1, 1
n-1, 0   ->  1, 0  

loop 2  
1, 1     ->  1, n-3  
1, n-2   ->  n-3, n-2  
n-2, n-2 ->  n-2,2
n-2, 1   ->  2, 1

loop i  
i-1, i-1    -> i-1, n-1-i  
i-1, n-i -> n-1-i, n-i
n-i, n-i -> n-i, i
n-i, i-1 -> i, i-1

```txt
# 代码

```java
public class Main {
	public static void print2D(int mat[][])
    {
        for (int[] row : mat) {
            for (int x : row) {
            	System.out.printf("%2d ", x);
            }
            System.out.println("");    
        }
        System.out.println("");
    }
 
	public static int[][] generateMatrix(int n) {
        int[][] result = new int[n][n];
        int cnt = 1;
        
        for(int i=1;i<=n/2;i++) {
        	for(int m=i-1;m<=n-1-i;m++) {
        		result[i-1][m] = cnt++;
        	}
        	for(int m=i-1;m<=n-1-i;m++) {
        		result[m][n-i] = cnt++;
        	}
        	for(int m=n-i;m>=i;m--) {
        		result[n-i][m] = cnt++;
        	}
        	for(int m=n-i;m>=i;m--) {
        		result[m][i-1] = cnt++;
        	}
        }
        
        if(n%2==1) {
        	result[n/2][n/2] = cnt;
        }
        return result;
    }
	public static void main(String[] args) {
		System.out.println("Hello Java!");
		for(int i=1;i<=4;i++) {
			int[][] spiralMatrix = generateMatrix(i);
			print2D(spiralMatrix);
		}
	}
}

```
