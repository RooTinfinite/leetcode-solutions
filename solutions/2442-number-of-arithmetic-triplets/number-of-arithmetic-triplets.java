class Solution {
    public int arithmeticTriplets(int[] nums, int diff) {
        int n = nums.length; 
        int[] hash = new int[n]; // hash[i] = index of (nums[i] + diff)
        
        for (int i = 0; i < n - 1; i++) {
            int next = nums[i] + diff;
            int j = i + 1;
            while (j < n && nums[j] <= next) { // find the next
                if (nums[j] == next) {
                    hash[i] = j;
                    break;
                }
                j++;
            }
        }
        
        int ans = 0;
        for (int i = 0; i < n - 1; i++) {
            if (hash[i] != 0 && hash[hash[i]] != 0) {
                ans++;
            }
        }
        return ans;
    }
}