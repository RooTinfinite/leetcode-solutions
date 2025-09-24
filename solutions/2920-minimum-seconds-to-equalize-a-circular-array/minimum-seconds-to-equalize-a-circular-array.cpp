class Solution {
public:
    int minimumSeconds(vector<int>& nums) {
        unordered_map<int , vector<int>> pos;
        int n = nums.size();
        for(int i = 0; i < n; ++i) pos[nums[i]].push_back(i);
        int res = INT_MAX;
        for(auto& [_ , vec] : pos){
            int len = vec.size();
            int seconds = (n + vec[0] - vec[len - 1]) / 2;
            for(int i = 1; i < len; ++i) seconds = max(seconds, (vec[i] - vec[i - 1]) / 2);
            res = min(res , seconds);
        }
        return res;
    }
};