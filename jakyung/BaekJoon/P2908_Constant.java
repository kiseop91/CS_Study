package baekjoon;
import java.util.*;
public class P2908 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s1 = sc.next();
		String s2 = sc.next();
		String[] sa1 = s1.split("");
		String[] sa2 = s2.split("");
		
		String lasts1 = new String();
		String lasts2 = new String();
		sc.close();
 
		for(int i =sa1.length-1;i>-1 ;i--) {
			lasts1 += sa1[i];
			lasts2 += sa2[i];
			
			
		}
		
		
		int last1 = Integer.parseInt(lasts1);
		int last2 = Integer.parseInt(lasts2);
		System.out.println(Math.max(last1, last2));
		

	}

}

