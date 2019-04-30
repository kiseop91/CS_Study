package baekjoon;
import java.util.*;
public class P7562 {

	static int[] dx = {-1,-2,-1,-2,1,2,1,2};
	static int[] dy = {-2,-1,2,1,-2,-1,2,1};
	static int n;
	static int[][] chess ,visit;
	static Queue<chessXYC> qu = new ArrayDeque<chessXYC>();
	
	public static void bfs(int x, int y,int count) {
		for(int i=0; i<8 ; i++) {
			if(x+dx[i] >-1 && x+dx[i] < n && y+dy[i] > -1 && y+dy[i] < n) {
				if(chess[x+dx[i]][y+dy[i]]==-1) {
					chess[x+dx[i]][y+dy[i]]= count + 1;
					qu.add(new chessXYC(x+dx[i],y+dy[i],count+1));
					
				}
			}
		}
	}
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int test = sc.nextInt();
	
		int[] result = new int[test];
		for(int t = 0; t < test; t++) {
			n =sc.nextInt();
			
			int knightX = sc.nextInt();
			int knightY = sc.nextInt();
			
			int endingX = sc.nextInt();
			int endingY = sc.nextInt();
			
			chess = new int[n][n];
			
			
			for(int i =0;i<n;i++)
				Arrays.fill(chess[i], -1);
		
			chess[knightX][knightY] = 0;
			qu.add(new chessXYC(knightX,knightY,0));
			
			while(!qu.isEmpty()) {
				
				
				chessXYC cxyc=qu.poll();
				
				bfs(cxyc.x,cxyc.y,cxyc.count);
				
				
				
			}

			
			
			result[t]= chess[endingX][endingY];
		}
		
		for(int i =0;i<result.length;i++)
			System.out.println(result[i]);
		
		sc.close();
		
	}

}
class chessXYC{
	int x;
	int y;
	int count;
	public chessXYC(int x, int y, int count) {
		this.x =x;
		this.y = y;
		this.count  = count;
		
	}
}

