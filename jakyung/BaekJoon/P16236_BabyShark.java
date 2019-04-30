//Samsung 2018 question

package baekjoon;
import java.util.*;
public class P16236 {

	static int[][] ocean;
	static int[][] visit;
	static int n, eatX, eatY, eatDistance, eateat, compiX,compiY,compiD,mx,my,md;
	static int[] dx= {0,1,0,-1};
	static int[] dy = {1,0,-1,0};
	static Queue<Shark> sharkqu = new ArrayDeque<Shark>();
	static Queue<Point> movequ = new ArrayDeque<Point>();
	
	public static void bfs(int x , int y, int size,int eat,int distance) {
		
		//baby shark move to find is there any fish to eat
		
		++distance;
		for(int i =0;i<4;i++) {
			if(x + dx[i] < n && y + dy[i] < n && x+dx[i] > -1 && y + dy[i] > -1) {
				if(ocean[x+dx[i]][y+dy[i]] == size || ocean[x+dx[i]][y+dy[i]] == 0) {
					if( visit[x+dx[i]][y+dy[i]] == -1) {
						/*this part that i got error don't write || && together..*/
						//there is no fish to eat then need to go to another way
						visit[x+dx[i]][y+dy[i]] = 1;
					
						movequ.add(new Point(x+dx[i],y+dy[i],distance));
					}
				}else if(ocean[x+dx[i]][y+dy[i]] > 0 && ocean[x+dx[i]][y+dy[i]] < size && visit[x+dx[i]][y+dy[i]]==-1) {
					//there is a fish to eat!!
					visit[x+dx[i]][y+dy[i]] = 1;
					
					mx = x+dx[i];
					my = y+dy[i];
					md = distance;
					/*this part that i got error
					  as a basic part bfs, the start point finds a 4 way in a same time. 
					  This means that if there a fish to eat in the way,
					  it can make at least 4 "same distance" and a "different X,Y" in a "same start point".
					  so, i should have compare with the X, Y one more time*/
					//compare the eatX, eatY
					if(eatX>mx) {
						
						eatX = mx;
						eatY = my;
						eatDistance = md;
					
					} else if(eatX == mx) {
						if(eatY >my) {
							eatX = mx;
							eatY = my;
							eatDistance = md;
							
						}
					}
					
					
				}else if (visit[x+dx[i]][y+dy[i]]==1) {
					continue;
				}
			}
			}
		}
	public static void init() {
		for(int i =0; i<n;i++) {
			Arrays.fill(visit[i],-1);
		}
	}
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		n = sc.nextInt();
		ocean  = new int[n][n];
		visit = new int[n][n];
	
		for(int i =0; i<n;i++) {
			for(int j=0; j<n;j++) {
				ocean[i][j] = sc.nextInt();
				if(ocean[i][j] == 9) {
					sharkqu.add(new Shark(i,j,2,0,0));
					ocean[i][j]=0;
				}
			}
		}
		
		init();
		
		sc.close();

		int result =0;
		
		while(!sharkqu.isEmpty()) {
			Shark shark =sharkqu.poll();
			int sharkX =shark.sharkX;
			int sharkY = shark.sharkY;
			int sharkSize = shark.sharkSize;
			int eat = shark.eat;
			int distance = shark.distance;
			result =distance;
		
			movequ.add(new Point(sharkX,sharkY,distance));
			//visit[sharkX][sharkY] =1;
			compiX = Integer.MAX_VALUE;
			compiY = Integer.MAX_VALUE;
			compiD = Integer.MAX_VALUE;
			
			while(!movequ.isEmpty()) {
				eatX = 99;
				eatY = 99;
				eatDistance = 99;
				mx=1000;
				my=1000;
				md=1000;
				Point point=movequ.poll();
				visit[point.x][point.y] = 1;
				bfs(point.x, point.y,sharkSize,eat,point.distance);
			
				if(eatX != 99 && eatY != 99) {
					//"different start point" has a different eatX,eatY, eatDistance. So you need to compare it
					if(compiD > eatDistance) {
						compiD = eatDistance;
						compiX = eatX;
						compiY = eatY;
					
					}else if(compiD == eatDistance) {
						
						if(compiX > eatX) {
							compiD = eatDistance;
							compiX = eatX;
							compiY = eatY;
							
						}else if(compiX == eatX) {
							if(compiY > eatY) {
								compiD = eatDistance;
								compiX = eatX;
								compiY = eatY;
								
								
							}
						}
					}else {
						
						movequ.clear();;
					
					}
					
					
				}
				
			}
		
			if(compiX != Integer.MAX_VALUE && compiY !=Integer.MAX_VALUE) {
			//now the final fish that the baby shark is going to eat is disappeared. 
			//then the baby shark position also changed to the final fish
				++eat;
				if(sharkSize == eat) {
					//if the eaten fish is same with the shark size. the baby shark grows up
					++sharkSize;
					ocean[compiX][compiY] =0;
				
					sharkqu.add(new Shark(compiX,compiY,sharkSize,0,compiD));
					
				}else {
					//if not, baby shark just go and find a other fish to eat.
					ocean[compiX][compiY] = 0;
				
					sharkqu.add(new Shark(compiX,compiY,sharkSize,eat,compiD));
					
				}
				
				
				
			}
			
			
		//placed a new baby shark position, reset the visit
			init();

		
		}
		
		System.out.println(result);
		
		
	}

}
class Point{
	int x;
	int y;
	int distance;
	public Point(int x, int y,int distance) {
		this.x = x;
		this.y = y;
		this.distance = distance;
	}
}

class Shark{
	int sharkX;
	int sharkY;
	int sharkSize;
	int eat;
	int distance;
	
	
	public Shark(int sharkX, int sharkY, int sharkSize, int eat, int distance) {
		this.sharkX = sharkX;
		this.sharkY = sharkY;
		this.sharkSize = sharkSize;
		this.eat = eat;
		this.distance = distance;
		
		
	}
	
}

