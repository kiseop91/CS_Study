package baekjoon;
import java.util.*;
public class P2839 {

	public static void main(String[] args) {
		   Scanner sc = new Scanner(System.in);
	        int n = sc.nextInt();
	        sc.close();
	         
	        int count = n / 5;
	         
	        switch (n % 5) {
	        case 0:
	            System.out.println(count);
	            break;
	        case 1:
	        case 3:
	            System.out.println(count + 1);
	            break;
	        case 2:
	            if (count < 2) {
	                System.out.println(-1);
	            } else {
	                System.out.println(count + 2);
	            }
	            break;
	        case 4:
	            if (count < 1) {
	                System.out.println(-1);
	            } else {
	                System.out.println(count + 2);
	            }
	            break;
	        }

	}

}

