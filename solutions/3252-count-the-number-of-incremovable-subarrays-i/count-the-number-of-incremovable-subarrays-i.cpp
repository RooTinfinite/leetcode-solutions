class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size(), count = 0;
        for(int l = 0; l < n; ++l){
            for(int r = l; r < n; ++r){
                bool valid = true;
                int prev = -1;
                for(int i = 0; i < n; ++i){
                    if(i >= l && i <= r) continue;
                    if(nums[i] <= prev){
                        valid = false;
                        break;
                    }
                    prev = nums[i];
                }
                if(valid) ++count;
            }
        }
        return count;
    }
};