class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans;
        bool lonely = true;
        for(int i=1; i<n; i++) {
            if(nums[i] != nums[i - 1]) {
                if(nums[i] - nums[i - 1] != 1) {
                    if(lonely) {
                        ans.push_back(nums[i - 1]);
                    }
                    lonely = true;
                }
                else {
                    lonely = false;
                }
            }
            else {
                lonely = false;
            }
        }
        if(lonely) {
            ans.push_back(nums[n - 1]);
        }
        return ans;
    }
};