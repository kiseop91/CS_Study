package baekjoon;

import java.util.*;

public class P17141 {

	static int n,virus,isThere0,result;
	static int[][] lab,visitVirus,copyLab ,copyLab2;
	static Queue<virusXY> qu = new ArrayDeque<virusXY>();
	static ArrayList<virusXY> virusList = new ArrayList<virusXY>();
	static int[] whichone,visit;
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,-1,0,1};
	static int min = Integer.MAX_VALUE;
	public static void bfs(Queue<virusXY> qu) {

		while(!qu.isEmpty()) {
			virusXY vxy=qu.poll();
			int x = vxy.x;
			int y = vxy.y;
			int count = vxy.count;
			for(int i =0;i<4;i++) {
				if(x+dx[i] > -1 && y+dy[i]>-1 && x+dx[i]<n && y+dy[i]<n) {
					if(copyLab2[x+dx[i]][y+dy[i]]==0) {
					
						copyLab2[x+dx[i]][y+dy[i]] = count+1;
						qu.add(new virusXY(x+dx[i],y+dy[i],count+1));
					}
				}
			}
			
			result = count;
		}
		
	}
	public static void combination(int x,int count,int size) {
		if(count==virus) {
		/*the reason that i made a new copyLab2 is to find if there are no 0
		 * if i just use the copyLab i can't reset the virus cuz i made the combination by backtracking
		 */
			copyLab2 = new int[n][n];
			for(int i =0;i<n ;i++)
				copyLab2[i]=Arrays.copyOf(copyLab[i], n);
			
			
			
			for(int i =0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(copyLab2[i][j] == -2) {
						qu.add(new virusXY(i,j,0));
					}
				}
			}
			//now it's going to spread the virus
			bfs(qu);
			
			//finding a place that didn't been polluted
			isThere0 =0;
			for(int i =0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(copyLab2[i][j] == 0) {
						isThere0 ++;
					}
				}
			}
			
			
			/* compare the result with min
			 * if there is 0 && haven't been no results before. need to make the min into -1
			 * but if there was a results and right now result is -1 just pass it
			 */
			if(isThere0 !=0) {
				if(min == Integer.MAX_VALUE || min ==-1)
					min=-1;
			}else {
				if(min==-1) 
					min =result;
				else
					min = Math.min(min, result);
			}
			
			
		}else {
			for(int i =x+1;i<size;i++) {
				if(visit[i]==-1) {
					visit[i]=1;
					copyLab[virusList.get(i).x][virusList.get(i).y] =-2;
					
					combination(i,count+1,size);
					
					copyLab[virusList.get(i).x][virusList.get(i).y] =0;
					visit[i]=-1;
					
				}
			}
			
		}
	}
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		n = sc.nextInt();
		virus = sc.nextInt();
		lab = new int[n][n];
		copyLab= new int[n][n];
		whichone = new int[virus];
	
		for(int i =0;i<n;i++) {
			for(int j =0; j<n;j++) {
				lab[i][j]= sc.nextInt();
				
				if(lab[i][j] == 2) {
					virusList.add(new virusXY(i,j,0));
					
				}
				
			}
		}
		
		visit = new int[virusList.size()];
		sc.close();
		Arrays.fill(visit, -1);
		
		
		for(int i  =0;i<virusList.size(); i++) {
			if(visit[i]==-1) {
				visit[i]=1;
				copyLab[virusList.get(i).x][virusList.get(i).y] =-2;
				
				combination(i,1,virusList.size());
				copyLab[virusList.get(i).x][virusList.get(i).y] =0;
				visit[i]=-1;
			}
		}
		
		System.out.println(min);

	}

}
class virusXY{
	int x;
	int y;
	int count;
	public virusXY(int x, int y, int count){
		this.x = x;
		this.y = y;
		this.count = count;
		
	}
	
}

