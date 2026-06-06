class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {
        vector<long long > ans;
        ans.push_back(nums[0]);
        for(int i = 1; i<nums.size(); i++){
            if(ans.back() == nums[i]) {
                ans.pop_back();
                long long curr = 1LL*nums[i]*2;
                while(!ans.empty() && curr == ans.back()){
                    ans.pop_back();
                    curr = curr * 2;
                }
                ans.push_back(curr);
            }
            else ans.push_back(nums[i]);
        }
        return ans;
    }
};