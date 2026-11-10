class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& locked, int k) {
        int n = nums.size();
        int mx = -1;
        int sol = 0;
        for(int i = 0; i < n ;i++){
            mx = max(nums[i], mx);
            if(locked[i] == 1){
                if(!(nums[i] == i+1 && mx == i + 1)){
                    sol++;
                }
            }
        }
        if(sol > k){
            return -1;
        }
        for(int i = 0;i < n; i++){
            for(int j = i + 1; j < n; j++){
                if(nums[i] > nums[j]){
                    sol++;
                }
            }
        }
        return sol;
    }
};