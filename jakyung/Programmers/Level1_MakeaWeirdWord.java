class Solution {
  public String solution(String s) {
      String[] sa = s.split(" ");
	      String answer = "";
	      for(int i =0; i<sa.length; i++) {
	    	  String a =sa[i];
	    	  String[] aa = a.split("");
	    	  String d ="";
	    	  
	    	  for(int j=0;j<aa.length;j++) {
	    		  if(j % 2 ==0) {
	    			 d+= aa[j].toUpperCase();
	    		  }else {
	    			  d+=aa[j].toLowerCase();
	    			 }
	    	  }
	    	  //sa[i]=d;
	    	 
	    	  if(i !=sa.length-1) {
	    		  answer += d +" ";
	    	  }else {
	    		  answer += d;
	    	  }
	      }
      int lastTrimLen = s.length() - answer.length();

	      for (int i = 0; i < lastTrimLen; i++) {
	            answer += " ";
	        }
	      
	      
	      return answer;
  }
}
