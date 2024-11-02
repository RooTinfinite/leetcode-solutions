class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ht;
        int tmp;
        for (int i = 0; i < nums.size(); ++i) {
            tmp = nums[i];
            if (ht.find(target-tmp) != ht.end()) {
                return {ht[target-tmp],i};
            }
            ht[tmp] = i;
        }
        return {};
    }
};