class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        for (int i = k;; i += k)
            if (find(nums.begin(), nums.end(), i) == nums.end())
                return i;
    }
};