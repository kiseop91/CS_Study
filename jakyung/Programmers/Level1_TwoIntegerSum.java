import java.util.*;
class Solution {
  public long solution(int a, int b) {
      long answer = 0;
      if(a != b){
          int bigone = Math.max(a,b);
          int smallone = Math.min(a,b);
          for(int i = smallone; i<=bigone ;i++){
              answer +=i;
          }
          
      }else{
          answer = a;
      }
      return answer;
  }
}
