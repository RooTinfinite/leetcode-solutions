class Solution {
public:
    int longestAlternatingSubarray(vector<int>& nums, int k) {
           int n = nums.size(), maxi = 0;

           for(int i = 0; i < n; ++i){
                if(nums[i] % 2 != 0 || nums[i] > k)continue;
                int cnt = 1;
                    for(int j = i+1; j < n; ++j){
                        if(nums[j] > k)break;
                        if(nums[j-1] % 2 == nums[j] % 2)break;
                        cnt++;
                    }
                    maxi = max(maxi,cnt);
           }
           return maxi;
    }
};