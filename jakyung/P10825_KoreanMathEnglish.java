package baekjoon;

import java.util.*;

public class P10825 {
	public String name;
	public int kor;
	public int eng;
	public int math;
	public P10825(String name, int kor, int eng, int math){
		this.name = name;
		this.kor = kor;
		this.eng = eng;
		this.math = math;
	}
	public String getName(){
		return name;
	}
	public void setName(String name){
		this.name = name;
	}
	public void setKor(int n){
		this.kor = n;
	}
	public int getKor(){
		return kor;
	}

	public void setEng(int n){
		this.eng = n;
	}
	public int getEng(){
		return eng;
	}
	public void setMath(int n){
		this.math = n;
	}
	public int getMath(){
		return math;
	}

	public static Comparator<P10825> Comparator = new Comparator<P10825_answer>(){
		public int compare(P10825 n1, P10825 n2){
			if(n1.getKor()<n2.getKor()){
				return 1;
			}
			else{
				if(n1.getKor()==n2.getKor()){
					if(n1.getEng()>n2.getEng()){
						return 1;
					}
					else{
						if(n1.getEng()==n2.getEng()){
							if(n1.getMath()<n2.getMath()){
								return 1;
							}
							else{
								if(n1.getMath()==n2.getMath()){
									if(n1.getName().compareTo(n2.getName())>0){
										return 1;
									}
									else{
										return -1;
									}
								}
								else{
									return -1;
								}
							}
						}
						else{
							return -1;
						}

					}
				}
				else{
					return -1;
				}
			}
		}
	};

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String sn = sc.nextLine();
		int n = Integer.parseInt(sn);
		P10825 baek[] = new P10825[n];
		//int i =0; 
		for(int i =0;i<n;i++) {
			String s=sc.nextLine();
			String[] sa = s.split(" ");
			
			baek[i] =  new P10825(sa[0],Integer.parseInt(sa[1])
					,Integer.parseInt(sa[2]),Integer.parseInt(sa[3]));
			//i++;
		}
		Arrays.sort(baek, Comparator);
		for(int j =0; j<baek.length; j++){
			System.out.println(baek[j].getName());
		}
		
		sc.close();
	}	
	}


