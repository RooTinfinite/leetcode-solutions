class Solution {
    public int countMajoritySubarrays(int[] nums, int target) {
        int pref[] = new int[nums.length + 1];
        pref[0] = 0;
        int p = 1;
        for (int i = 0; i < nums.length; i++) {
            pref[p] = pref[p - 1] + (nums[i] == target ? 1 : 0);
            p++;
        }
        int count = 0;
        for (int i = 0; i < nums.length; i++) {
            for (int j = i; j < nums.length; j++) {
                int length = (j+1) - (i+1) + 1;
                int totalElement = pref[j+1] - pref[i];
                if((2*totalElement) > length) {
                   count++; 
                }
            }
        }
       return count; 
    }
}