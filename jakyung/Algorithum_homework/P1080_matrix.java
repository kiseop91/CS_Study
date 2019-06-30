package baekjoon;
import java.util.*;
public class P1080 {
	public static int[][] A;
	
	public static void changeA(int col, int row) {
		
		for(int i = row; i<row+3;i++) {
			for(int j = col; j < col+3; j++) {
				
				if(A[i][j] == 0) {
					A[i][j] = 1;
				}else {
					A[i][j] =0;
				}
			}
		}
		
		
	
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String line = sc.nextLine();
		String[] ss = line.split(" ");
		int n = Integer.parseInt(ss[0]);
		int m = Integer.parseInt(ss[1]);
		//System.out.println("n : "+n +" m : "+m);
		A = new int[n][m];
		int[][] B = new int[n][m];
		
		
		for(int i =0;i<n;i++) {
			String ll = sc.nextLine();
			String[] ls = ll.split("");
			for(int j =0;j<m;j++) {
				A[i][j] = Integer.parseInt(ls[j]);
				
			}
			
		}
		for(int i =0;i<n;i++) {
			String ll = sc.nextLine();
			String[] ls = ll.split("");
			for(int j =0;j<m;j++) {
				B[i][j] = Integer.parseInt(ls[j]);
				
			}
			
		}
		sc.close();
		
		int col = m-3;
		int row = n-3;
		
		
		int count =0;;
		for(int i =0; i<=row;i++) {
			for(int j = 0; j<=col;j++) {
				
				if(A[i][j] != B[i][j]) {
							
					changeA(j,i);
					count++;
				}
			}
				
		}
		int flag =0;
		for(int i =0;i<n ;i++) {
			for(int j =0; j<m ;j++) {
				
				if(A[i][j] != B[i][j]) {
					flag = -1;
				}
			}
			
		}
		
		if(flag !=0 ) System.out.println(flag);
		else System.out.println(count);
	}

}

