package baekjoon;
import java.util.*;
public class P17142 {

	static int n,virus,p,result,isThere0;
	static int[][] lab3,copyLab, visitLab;
	static int[] visit;
	static ArrayList<virusXY> virusList= new ArrayList<virusXY>();
	static ArrayList<virusXY[]> combiVirusList = new ArrayList<virusXY[]>();
	static virusXY[] vv;
	static Queue<virusXY3> qu = new ArrayDeque<virusXY3>();
	static int[] dx = {-1,0,1,0};
	static int[] dy = {0,1,0,-1};
	static int min = Integer.MAX_VALUE;
	
	public static void bfs() {
		
		while(!qu.isEmpty()) {
			virusXY3 vxy=qu.poll();
			int x = vxy.x;
			int y= vxy.y;
			int count = vxy.count;
			int whichone = vxy.whichone;
			
			for(int i =0;i<4;i++) {
				if(x+dx[i] > -1 && x+dx[i]<n && y+dy[i] >-1 && y+dy[i]<n) {
					if(copyLab[x+dx[i]][y+dy[i]] ==0 && visitLab[x+dx[i]][y+dy[i]]==-1) {
						visitLab[x+dx[i]][y+dy[i]]=1;
						copyLab[x+dx[i]][y+dy[i]] = count+1;
					
						qu.add(new virusXY3(x+dx[i],y+dy[i],count+1,0));
					}else if(copyLab[x+dx[i]][y+dy[i]] == -3 && visitLab[x+dx[i]][y+dy[i]]==-1){
						visitLab[x+dx[i]][y+dy[i]]=1;
						qu.add(new virusXY3(x+dx[i],y+dy[i],count+1,-3));
					}
				}
			}
			
			if(whichone !=-3)
			result = count;
			
		}
		
	}
	
	public static void makeCombination(int x,int count) {
		if(count == virus) {
		
			virusXY[] vcopy = new virusXY[virus];
			vcopy=Arrays.copyOf(vv, vv.length);
			combiVirusList.add(vcopy);
			
		}else {
			
			for(int i = x+1;i<visit.length;i++) {
				if(visit[i] == -1) {
					visit[i] = 1 ; 
					vv[count] = new virusXY(virusList.get(i).x, virusList.get(i).y, virusList.get(i).count);
					makeCombination(i,count+1);
					visit[i] = -1;
				}
			}
		}
	}
	
	
	public static void main(String[] args) {
		Scanner sc= new Scanner(System.in);
		n = sc.nextInt();
		virus = sc.nextInt();
		lab3 = new int[n][n];
		copyLab = new int[n][n];
		visitLab = new int[n][n];
		for(int i =0;i<n;i++) {
			for(int j =0; j<n; j++) {
				int l = sc.nextInt();
				
				if(l==1) {
					lab3[i][j]=-1;
				}
				if(l == 2) {
					virusList.add(new virusXY(i,j,0));
					lab3[i][j]= -3;
					
				}
				copyLab[i][j] = lab3[i][j];
				
			}
		}
		sc.close();
		visit = new int[virusList.size()];
		Arrays.fill(visit, -1);
		vv= new virusXY[virus];
		p=0;
		for(int i =0; i< visit.length;i++) {
			if(visit[i] == -1) {
				visit[i] = 1;
				vv[0] = new virusXY(virusList.get(i).x, virusList.get(i).y, virusList.get(i).count);
				makeCombination(i,1);
				visit[i] = -1;
			}
		}
		
		//now going to start to spread the virus up
		for(int t =0;t<combiVirusList.size();t++) {
			
			//activating the chosen virus
			virusXY[] vvv = combiVirusList.get(t);
			for(int j =0;j<vvv.length;j++) {
				copyLab[vvv[j].x][vvv[j].y] = -2;
				
				qu.add(new virusXY3(vvv[j].x,vvv[j].y,0,-2));
				
			}
			
			//reset the visitLab
			for(int i =0;i<n;i++) 
				Arrays.fill(visitLab[i], -1);
			
			result =0;
			bfs();
			
			//finding a place that didn't been polluted
			isThere0 =0;
			for(int i =0;i<n;i++) {
				for(int j=0;j<n;j++) {
					if(copyLab[i][j] == 0) {
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
					min = result;
				else
					min = Math.min(min, result);
			}
			
			for(int j =0 ; j<n;j++) 
				copyLab[j]=Arrays.copyOf(lab3[j], n);
			
		}
		System.out.println( min);

	}

}
class virusXY3{
	int x;
	int y;
	int count;
	int whichone;
	virusXY3(int x, int y, int count, int whitchone){
		this.x = x;
		this.y = y;
		this.count = count;
		this.whichone = whitchone;
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

