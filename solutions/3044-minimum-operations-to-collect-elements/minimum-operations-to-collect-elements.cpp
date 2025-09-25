class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> v;
        int arrsize = nums.size();
        
        for (int i=arrsize-1; i>=0; i--){
            
            if (nums[i] <= k){
                v.insert(nums[i]); 
            }
                
            if(v.size() == k){
                return arrsize-i;
            }
                
        }
        
        return arrsize;
    }
};