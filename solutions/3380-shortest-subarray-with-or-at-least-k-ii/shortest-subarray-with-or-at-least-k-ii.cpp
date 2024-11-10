class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        if (k == 0) {
            return 1;
        }
        int shortest = nums.size() + 1;
        int count[32] = {};
        int val = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); ++i) {
            int num = nums[i];
            val |= num;
            for (int ibit = 0; num; ++ibit) {
                count[ibit] += num & 1;
                num >>= 1;
            }
            while (val >= k && start < nums.size()) {
                shortest = min(shortest, i - start + 1);
                num = nums[start];
                ++start;
                for (int ibit = 0; num; ++ibit) {
                    count[ibit] -= num & 1;
                    if (count[ibit] == 0) {
                        val &= ~(1 << ibit);
                    }
                    num >>= 1;
                }
            }
        }
        return shortest == (nums.size() + 1) ? -1 : shortest;
    }
};