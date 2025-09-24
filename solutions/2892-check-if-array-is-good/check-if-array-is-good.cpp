class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (auto i=0, j=1; i<nums.size(); i++, j++) {
            if (j == nums.size()) --j; /* decrease at the end */
            if (nums[i] != j) return false;
        }
        return true;
    }
};