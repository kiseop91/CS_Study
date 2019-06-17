package baekjoon;
import java.util.*;
public class P11399 {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] time = new int[n];
		for(int i =0;i<n ;i++) {
			time[i] = sc.nextInt();
		}
		sc.close();
		Arrays.sort(time);
		int l = n;
		int result =0;
		for(int i =0;i<n;i++) {
			result += time[i] * l;
			l--;
		}
		System.out.println(result);
		
	}

}

