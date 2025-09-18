class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
        int pairs = 0, left = 0;
        unordered_map<int, int> mp;
        for(int i : nums){
            mp[i]++;
        }

        for(const auto& pair : mp){
            pairs += pair.second / 2;
            left += pair.second % 2;
        }

        return {pairs, left};
        
    }
};