
class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        if(nums.size() < 2) return false;
        
        unordered_map<int, int> freq;
        
        for(int i = 0; i < nums.size() - 1; i++){
            int sum = nums[i] + nums[i + 1];
            if(freq[sum] > 0) return true;
            freq[sum]++;
        }
        
        return false;
    }
};