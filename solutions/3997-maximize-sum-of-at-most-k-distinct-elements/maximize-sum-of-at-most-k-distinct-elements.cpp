class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.rbegin(),nums.rend());
        int i = 1;
        vector<int>res;
        res.push_back(nums[0]);
        k--;
        while(k>0 && i < n){
            if(nums[i] != nums[i-1]){
                res.push_back(nums[i]);
                k--;
            }
            i++;
             }
        return res;
        
    }
};