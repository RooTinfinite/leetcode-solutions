class Solution {
public:
    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        long long cnt = 0;
        for (int i = 0; i < n; ++i) {
            int add = nums[i];
            int minVal = nums[i];
            for (int j = i; j < n; ++j) {
                add &= nums[j];
                if (nums[j] < minVal) {
                    minVal = nums[j];
                }
                if (add == minVal) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};