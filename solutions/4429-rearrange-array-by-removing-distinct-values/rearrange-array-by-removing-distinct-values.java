import java.util.ArrayList;
import java.util.List;

class Solution {
    public int[] rearrangeArray(int[] nums) {
        int[] freq = new int[101];
        int maxFreq = 0;

        for (int x : nums) {
            freq[x]++;
            if (freq[x] > maxFreq) {
                maxFreq = freq[x];
            }
        }

        int[] ans = new int[nums.length];
        int idx = 0;

        for (int round = 0; round < maxFreq; round++) {
            for (int val = 1; val <= 100; val++) {
                if (freq[val] > 0) {
                    ans[idx++] = val;
                    freq[val]--;
                }
            }
        }

        return ans;
    }
}