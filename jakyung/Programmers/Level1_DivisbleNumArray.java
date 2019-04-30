import java.util.*;

class Solution {
  public int[] solution(int[] arr, int divisor) {
      PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
     // String s = "";
      for(int i=0 ;i<arr.length;i++){
          if(arr[i]% divisor ==0){
              pq.add(arr[i]);
             // s +=arr[i]+"";
          }
      }
      int[] answer;
      if(pq.size() == 0){
          answer = new int[1];
          answer[0] = -1;
      }else{
          answer = new int[pq.size()];
          for(int i =0;i<answer.length;i++){
              answer[i]=pq.poll() ;
          }
              
      }
      
      
      return answer;
  }
}
