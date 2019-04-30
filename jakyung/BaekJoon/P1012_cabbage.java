package baekjoon;
import java.util.*;
public class P1012 {
	static int n,m,k;	
	static int[][] highcoolland,visit;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	public static void dfs(int x , int y) {
		
		for(int i=0; i <4; i++) {
			
			if(x+dx[i] > -1 && x+dx[i] < n && y+dy[i] >-1 && y+dy[i]<m) {
				
				if(highcoolland[x+dx[i]][y+dy[i]] == 1 && visit[x+dx[i]][y+dy[i]] == -1) {
					visit[x+dx[i]][y+dy[i]]=1;
					
				
					dfs(x+dx[i],y+dy[i]);
				}
			}
		}
	}

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		int testcase = sc.nextInt();
		int[] result = new int[testcase];
		
		for(int t =0;t<testcase;t++) {
		
			m = sc.nextInt();
			n = sc.nextInt();
			k = sc.nextInt();
			highcoolland = new int[n][m];
			visit = new int[n][m];
			for(int i =0;i<n;i++) {
				Arrays.fill(highcoolland[i], 0);
				Arrays.fill(visit[i],-1);
			}
			for(int i = 0; i< k;i++) {
				int y = sc.nextInt();
				int x = sc.nextInt();
				highcoolland[x][y] = 1;
				
			}
		
			
			int count =0;
			for(int i =0; i < n ;i++) {
				for(int j =0; j <m;j++) {
					
					if(highcoolland[i][j]==1 && visit[i][j]== -1) {
						visit[i][j]=1;
						count++;
						dfs(i,j);
						
						
					}
					
					
				}
			}
			
			
			result[t] = count;
			
			
			
		}
		for(int i =0; i<result.length;i++)
			System.out.println(result[i]);
		sc.close();

}

		
	

}
