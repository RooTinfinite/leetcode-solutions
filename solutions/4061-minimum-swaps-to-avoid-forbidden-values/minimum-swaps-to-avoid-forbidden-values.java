class Solution {
    public int minSwaps(int[] nums, int[] forbidden) {
        int n = nums.length;
        
        // Maps for feasibility check
        Map<Integer, Integer> numsCnt = new HashMap<>();
        Map<Integer, Integer> forbiddenCnt = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            numsCnt.put(nums[i], numsCnt.getOrDefault(nums[i], 0) + 1);
            forbiddenCnt.put(forbidden[i], forbiddenCnt.getOrDefault(forbidden[i], 0) + 1);
        }
        
        // 1. Feasibility Check (Pigeonhole Principle)
        for (int num : numsCnt.keySet()) {
            int count = numsCnt.get(num);
            int blocked = forbiddenCnt.getOrDefault(num, 0);
            
            // If the count of a number exceeds available valid spots
            if (count > n - blocked) {
                return -1;
            }
        }
        
        // 2. Count Conflicts and Find Majority Bad Element
        int totalConflicts = 0;
        int maxFreq = 0;
        Map<Integer, Integer> badCnts = new HashMap<>();
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == forbidden[i]) {
                totalConflicts++;
                int currentBadCount = badCnts.getOrDefault(nums[i], 0) + 1;
                badCnts.put(nums[i], currentBadCount);
                maxFreq = Math.max(maxFreq, currentBadCount);
            }
        }
        
        if (totalConflicts == 0) return 0;
        
        // 3. Calculate Swaps
        int pairs = Math.min(totalConflicts / 2, totalConflicts - maxFreq);
        
        return totalConflicts - pairs;
    }
}