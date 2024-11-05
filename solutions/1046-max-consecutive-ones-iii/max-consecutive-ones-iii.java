class Solution {
    public int longestOnes(int[] A, int K) {
        
        int start=0, end = 0;
        int n = A.length;
        int max = 0;
        while(end < n){
            if(A[end] == 1) end++;  //expand right boundry
            else if(A[end] == 0 && K>0){ //expand right boundry but decrease K(to keep track of zeroes)
                K--;
                end++;  
            }
            else{ //case when K becomes 0
                max = Math.max(end-start, max); //try to update the answer
                if(A[start] == 0) K++;  //if left boundry had a zero then increase the K, so we can later use it
                start++; //then move the left boundry
            }
        }
        
        return Math.max(max,end-start); //in our loop we are only updating the answer when K becomes zero. What if K doesnt become zero ? , so that's why check for the larger window before returning the answer also.
    }
}