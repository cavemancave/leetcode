
# 代码
m, n 分不清的时候，就写出来，在注释里会看的更清楚一点。
```java


import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * Learn Java from https://www.liaoxuefeng.com/
 * 
 * @author liaoxuefeng
 */
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
	//m row , n col
	public static int[][] generateMatrix(int m, int n){
		int[][] matrix = new int[m][n];
		int cnt = 1;
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				matrix[i][j] = cnt++;
			}
		}
		return matrix;
	}
	public static List<Integer> spiralOrder(int[][] matrix) {
		List<Integer> list = new ArrayList<>();
		int row = matrix.length;
		int col = matrix[0].length;
		int loop_total = Math.min(row/2, col/2);
		int i=0;
		int j=0;
		int loop=0;
		for(loop=0;loop<loop_total;loop++) {
			i=loop;
			j=loop;
			for(;j<col-1-loop;j++) {
				list.add(matrix[i][j]);
			}
			for(;i<row-1-loop;i++) {
				list.add(matrix[i][j]);
			}
			for(;j>loop;j--) {
				list.add(matrix[i][j]);
			}
			for(;i>loop;i--) {
				list.add(matrix[i][j]);
			}
		}
		if(row%2==1) {
			if(col %2==1) {
				list.add(matrix[row/2][col/2]);
			}else {
				for(j=loop;j<=col-1-loop;j++) {
					list.add(matrix[loop][j]);
				}
			}
		}else {
			
			if(col %2==1) {
				for(i=loop;i<=row-1-loop;i++) {
					list.add(matrix[i][loop]);
				}
			}
		}
		return list;
    }
	public static void main(String[] args) {
		System.out.println("Hello Java!");
		int[][] spiralMatrix;
		List<Integer> spiralList;
		spiralMatrix = generateMatrix(2,1);
		print2D(spiralMatrix);
		spiralList = spiralOrder(spiralMatrix);
		System.out.println(spiralList.toString());
		
	}
}

```
