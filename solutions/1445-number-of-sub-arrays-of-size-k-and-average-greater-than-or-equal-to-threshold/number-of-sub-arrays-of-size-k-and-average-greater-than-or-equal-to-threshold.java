class Solution {
    public int numOfSubarrays(int[] arr, int k, int threshold) {
        int n = arr.length;
        
        // 1. Pre-calculate the minimum required sum (use long to prevent potential overflow 
        //    if k and threshold are very large, although constraints allow int here)
        int requiredSum = k * threshold;
        int count = 0;
        
        // 2. Calculate the sum of the initial window
        int currentSum = 0;
        for (int i = 0; i < k; i++) {
            currentSum += arr[i];
        }
        
        // 3. Check and count the initial window
        if (currentSum >= requiredSum) {
            count = 1;
        }
        
        // 4. Slide the window from index k to n-1
        for (int i = k; i < n; i++) {
            // Update Sum: Subtract the element leaving the window (at i-k)
            // and add the new element entering the window (at i)
            currentSum = currentSum - arr[i - k] + arr[i];
            
            // Check the condition for the new window
            if (currentSum >= requiredSum) {
                count++;
            }
        }
        
        return count;
    }
}