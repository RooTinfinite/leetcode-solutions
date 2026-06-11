class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> mp,freq;
        for(int i = 0; i < nums.size(); i++) mp[nums[i]]++;
        for(auto& it: mp) freq[it.second]++;
        for(auto it: nums) if(freq[mp[it]] == 1) return it;
        return -1;
    }
};