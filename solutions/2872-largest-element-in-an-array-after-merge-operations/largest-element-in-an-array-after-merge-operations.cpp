class Solution {
public:
    long long maxArrayValue(vector<int>& nums) {
        size_t n = nums.size(), i = n - 1;
        long long output = nums[n - 1];
        while (i--) {
            if (nums[i] > output) output = nums[i];
            else output += nums[i];
        }
        return output;
    }
};