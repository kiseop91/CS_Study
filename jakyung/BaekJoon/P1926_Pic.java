package baekjoon;

import java.util.*;
public class P1926 {
	static int max = Integer.MIN_VALUE;
	static int howmuch,n,m;
	static int[][] paper,visit;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	public static void dfs(int x, int y) {
		++howmuch;
		for(int i =0;i<4 ;i++) {
			if(x+dx[i]>-1 && x+dx[i]<n && y+dy[i] > -1 && y+dy[i]<m) {
				if(paper[x+dx[i]][y+dy[i]] == 1 && visit[x+dx[i]][y+dy[i]] ==-1) {
					visit[x+dx[i]][y+dy[i]] = 1;
					
					dfs(x+dx[i],y+dy[i]);
				}
				
			}
		}
	}

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		m = sc.nextInt();
		paper = new int[n][m];
		visit = new int[n][m];
		for(int i =0; i<n;i++) {
			for(int j = 0; j<m ; j++) {
				paper[i][j] = sc.nextInt();
				
				//System.out.print(paper[i][j] + " ");
			}
		}
		
		for(int i =0; i<n ; i++) {
			Arrays.fill(visit[i], -1);
		}
		
		sc.close();
		
		
		int pics = 0; 
		for(int i =0; i<n; i++) {
			for(int j = 0; j<m; j++) {
			//	int count =0;
				howmuch =0;
				if(paper[i][j]==1 && visit[i][j]==-1) {
					pics++;
					visit[i][j]=1;
					dfs(i,j);
					
				}
				
				if(max<howmuch) {
					max=howmuch;	
				}
			}
		}
		
		System.out.println(pics);
		System.out.println(max);

	}
}

class PicXY{
	int x;
	int y;
	int count;
	public PicXY(int x,int y,int count) {
		this.x=x;
		this.y=y;
		this.count = count;
	}
}
