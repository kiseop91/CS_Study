package baekjoon;
import java.util.*;
public class P10610 {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		String[] sa = s.split("");
		Integer[] nn = new Integer[sa.length];
		int result3 =0;
		int count0 =0;
		for(int i =0;i<sa.length;i++) {
			nn[i] = Integer.parseInt(sa[i]);
			result3 += Integer.parseInt(sa[i]);
			if(Integer.parseInt(sa[i]) == 0) count0++;
		}
		
		if(count0 == 0 || result3 % 3 !=0) {
			System.out.println("-1");
		}else {
			Arrays.sort(nn,Collections.reverseOrder());
			for(int i : nn)
				System.out.print(Integer.toString(i));
		}
		
		sc.close();
	}

}

