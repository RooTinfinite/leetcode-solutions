class Solution {
    public static int earliestTime(int[][] tasks) {
        
    	int n = tasks.length;
    	int ans = Integer.MAX_VALUE;
    	
    	for (int i = 0; i < n; i++) {
			
    		int finish = tasks[i][0] + tasks[i][1]; 
    		
    		
    		if(finish < ans) {
    			ans =  finish;
    		}
		}
    	
    	return ans;
    	
    }
}