package baekjoon;

import java.util.*;
public class P2292 {
/*
 the reason i got a error
 1. used to much of memory
  > first i made array of visit[]. when ever i fill the array into -1, i used lot of memory.(then the result comes out kinda slow)
  but i don't know how to calculate the memory size
 
 2. when n==1
 > the first while start as n >=2 so, the n==1 result comes out wrong.*/
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		sc.close();
		int x =1; 
		int start = 1;
		if(n == 1) {
			System.out.println(1);
		}else {
			while(true) {
				
				
					if(n-1 >= start &&(n-1)<start + (x*6)) {
						
						System.out.println(x+1);
						return;
					}
				
						start = start + (x*6);
						x++;
					
			}
		}
		
	}

}

