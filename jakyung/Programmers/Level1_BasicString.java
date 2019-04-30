class Solution {
  public boolean solution(String s) {
     boolean answer;
     if(s.length() ==4 || s.length() ==6){
          int num=0;
      for(int i =0;i<s.length();i++){
          int index = s.charAt(i);
          if(index >=48 && index <=57) {
              num++;
          }
      }
       
      if(num == s.length()){
          answer=true;
      }else{
          answer = false;
      }
      
     }else{
         answer = false;
     }
      
      
     
      return answer;
  }
}
