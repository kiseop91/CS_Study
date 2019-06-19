package baekjoon;
import java.util.*;

public class P11047 {

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int k = sc.nextInt();
		int[] money = new int[n];
		for(int i =0;i<n ;i++) {
			money[i] = sc.nextInt();
		}
		sc.close();
		int result =0;
		for(int i =n-1;i>-1;i--) {
			result += k/money[i];
			k = k % money[i];
		}
		System.out.println(result);
	}

}

