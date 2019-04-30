package baekjoon;
import java.util.*;
public class P4811 {
/*
this problem is DP
need to study more...
*/
	public static long[][] map;
	
	public static long combi(int whole, int half) {
		if(whole>0) {
			//System.out.println("whole>0");
			if(map[whole][half]!=0) {
				//System.out.println("whole : "+whole +" half : "+ half);
				return map[whole][half];
			}
		}
		if(whole ==0) {
			//System.out.println("whole == 0");
			//System.out.println("whole : "+whole +" half : "+ half);
			map[whole][half] =1;
			return 1;
			
		}else {
			//System.out.println("come to else");
			long sum = 0;
			sum+= combi(whole-1,half+1);
			if(half >=1)
				sum += combi(whole, half-1);
			map[whole][half] = sum;
			return sum;
		}
		
	}
	
	
	
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		//int i =1;
		ArrayList<Long> result = new ArrayList<Long>();
		while(sc.hasNext()) {
			int test = sc.nextInt();
			if(test == 0) {
				break;
			}else {
			
				map = new long[2*test+1][2*test+1];
				int whole = test-1;
				int half = 1;
				result.add(combi(whole,half));
				
				for(int i =0;i<map.length;i++) {
					for(int j=0;j<map[i].length;j++) {
						//System.out.println(map[i][j] +" ");
					}
					//System.out.println("");
				}
				//System.out.println(i+" : "+ test);
				//i++;
				
			}
		}
		for(int i =0;i<result.size();i++)
			System.out.println(result.get(i));
		
		
		sc.close();
	}

}

