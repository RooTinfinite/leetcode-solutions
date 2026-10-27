class Solution {
public:
    int resilientSubarray(vector<int>& nums, int k) {
        for(int i = 0; i < nums.size(); i++){
            nums[i] = (nums[i]) % k;
        }
        long long int sol = 1;
        long long int curr = 1;
        int n = nums.size();
        for(int i = 1; i < n; i++){
            if(nums[i-1] == nums[i]){
                curr++;
                if((nums[i]*(curr-1)) % k == 0){
                    sol = max(sol, curr);
                }
            }else{
                curr = 1;
            }
        }
        return sol;
    }
};