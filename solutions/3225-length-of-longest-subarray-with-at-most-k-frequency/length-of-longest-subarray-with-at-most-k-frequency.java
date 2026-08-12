class Solution {
    public int maxSubarrayLength(int[] nums, int k) {
        int n = nums.length;
        Map<Integer, Integer> frequency = new HashMap();
        int start = 0;
        int charsWithFreqOverK = 0;
        
        for (int end = 0; end < n; end++) {
            frequency.put(nums[end], frequency.getOrDefault(nums[end], 0) + 1);
            if (frequency.get(nums[end]) == k + 1) { 
                charsWithFreqOverK++;
            }
            if (charsWithFreqOverK > 0) { 
                frequency.put(nums[start], frequency.get(nums[start]) - 1); 
                if (frequency.get(nums[start]) == k) { 
                    charsWithFreqOverK--; 
                }
                start++;
            }
        }
        return n - start; 
    }
}