class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOps) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        while (low < high) {
            int mid = low + (high - low) / 2;
            int ops = 0;
            for (int n : nums) {
                ops += ceil((double)n / mid) - 1;
                if (ops > maxOps) break;
            }
            ops <= maxOps ? high = mid : low = mid + 1;
        }
        return high;
    }
};