class Solution {
  public String solution(String s) {
      String[] sa = s.split("");
      String answer = "";
      if(s.length() %2==0){
          answer = sa[s.length()/2-1]+sa[s.length()/2];
      }else{
          answer = sa[s.length()/2];
      }
     
      return answer;
  }
}
