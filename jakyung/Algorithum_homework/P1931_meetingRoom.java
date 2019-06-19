package baekjoon;
import java.util.*;
public class P1931 {
	
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		ArrayList<TimeSE> al = new ArrayList<TimeSE>();
		
		for(int i =0;i<n;i++) {
			int start = sc.nextInt();
			int end = sc.nextInt();
			al.add(new TimeSE(start,end));
		}
		sc.close();
		TimeSEComparator tc = new TimeSEComparator();
		Collections.sort(al, tc);
		TimeSE tse = al.get(0);
		int result=1;
		for(int i =1;i<al.size();i++) {
			TimeSE tse2 = al.get(i);
			if(tse2.start >= tse.end) {
				tse =tse2;
				result++;
			}
		}

		System.out.println(result);
		
	}

}
class TimeSE{
	int start;
	int end;
	public TimeSE(int start , int end) {
		this.start = start;
		this.end = end;
	}
	
}
class TimeSEComparator implements Comparator<TimeSE>{

	@Override
	public int compare(TimeSE o1, TimeSE o2) {
		if(o1.end >o2.end)return 1;
		if(o1.end < o2.end)return -1;
		if(o1.end == o2.end) {
			if(o1.start >o2.start) return 1;
			else return -1;
		}
		return 0;
	}
	
}
