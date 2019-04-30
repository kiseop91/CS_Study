package baekjoon;
import java.util.*;
public class P1748 {

	public static void main(String[] args) {
		 Scanner sc = new Scanner(System.in);
		 String s = sc.next();
		 int n = Integer.parseInt(s);
		 int length = s.length();
		 int result =0;
		 
		 for(int i =1; i <= length-1; i++) {
			 result += 9*Math.pow(10, i-1)*i;
		 }
		 
		 
		 result += (n-(int)Math.pow(10, length-1)+1) * length;
		 System.out.println(result);
	     sc.close();
		
	}

}

