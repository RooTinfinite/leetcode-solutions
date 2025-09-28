class Solution {
public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long operations = 0;

        int median = nums[n / 2];
        if (k == median)
            return 0;

        if (k > median) {
            for (int i = n / 2; i < n && nums[i] < k; ++i)
                operations += k - nums[i];
        } 
        else {
            for (int i = n / 2; i >= 0 && nums[i] > k; --i)
                operations += nums[i] - k;
        }

        return operations;

    }
};