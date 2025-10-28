class Solution {
    public int maxFrequency(int[] nums, int k) {
        
        int maxOverAll = 0;
        int totalKfreq = 0;
        Set<Integer> set = new HashSet<>();

        for(int n : nums) {
            set.add(n);
            if(n == k) {
                totalKfreq++;
            }
        }
        
        for(int n : set) {
            
            if(n == k) {
                continue;
            }

            int currFreq = 0;
            int max = 0;

            for(int i = 0; i < nums.length; i++) {
                currFreq = currFreq - (nums[i] == k ? 1 : 0) + (nums[i] == n ? 1 : 0);
                max = Math.max(currFreq, max);
                if(currFreq < 0) {
                    currFreq = 0;
                }
            }

            maxOverAll = Math.max(maxOverAll, max);
        }

        return totalKfreq + maxOverAll;
    }
}