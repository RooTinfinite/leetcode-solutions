class Solution {
public:
    vector<int> delayedCount(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res(n, 0);
        unordered_map<int, int> freq;
        for (int i = n - 1; i >= 0; i--) {
            res[i] = freq[nums[i]];
            if (i + k < n)
                freq[nums[i + k]]++;
        }
        return res;
    }
};