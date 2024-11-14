// Runtime: 3 ms, faster than 92.99% of Java online submissions for Summary Ranges.
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
    public List<String> summaryRanges(int[] nums) {
        // Create a list of string to store the output result...
        List<String> output = new ArrayList<String>();
        // Start traversing the array from idx = 0 till idx < sizeofarray in a while loop.
        int idx = 0;
        while(idx < nums.length) {
            // Initialize beg and last index for identifying the continuous element in the array...
            int beg, last;
            // Mark the number at current index as beginning element of the range...
            beg = nums[idx];
            // Traverse the array beggining from current index & find the last element whose difference from previous element is exactly 1, i.e. nums[idx + 1] == nums[idx] + 1...
            while(idx+1 < nums.length && nums[idx+1] == nums[idx] + 1) 
                idx++;
            // Set this element as last element of the range...
            last = nums[idx];
            // If continuous element isn't present...
            if(beg == last)
                output.add(beg + "");
            // If present...
            else
                output.add( beg + "->" + last );
            idx++;          
        }
        return output;      // Return the output result list...
    }
}