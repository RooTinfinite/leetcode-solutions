class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_set<int> hash;
        int i = 0;
        for(i = nums.size() - 1; i >= 0; i--) {
            if (hash.count(nums[i])) break;
            hash.insert(nums[i]);
        }
        return (i + 3) / 3;
    }
};