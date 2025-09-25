class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int mini = 0, maxi = 0;
        for (int i = indexDifference, n = nums.size(); i < n; ++i) {
            int prevIdx = i - indexDifference;
            if (nums[prevIdx] < nums[mini]) mini = prevIdx;
            if (nums[prevIdx] > nums[maxi]) maxi = prevIdx;
            if (nums[i] - nums[mini] >= valueDifference) return {mini, i};
            if (nums[maxi] - nums[i] >= valueDifference) return {maxi, i};
        }
        return {-1, -1};
    }
};