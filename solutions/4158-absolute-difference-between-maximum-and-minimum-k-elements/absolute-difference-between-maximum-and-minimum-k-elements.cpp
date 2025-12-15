class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int max_sum = 0, min_sum = 0;
        for(int i = 0, j = nums.size() - 1; i < k; i++, j--) {
            min_sum += nums[i];
            max_sum += nums[j];
        }
        return max_sum - min_sum;
    }
};