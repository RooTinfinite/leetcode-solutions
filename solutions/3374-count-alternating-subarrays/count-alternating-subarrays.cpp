class Solution {
public:
    long long countAlternatingSubarrays(vector<int>& nums) {
        long long ans = 0; 
        
        //count all same 
        long long n = nums.size(); 
        ans = n;  
        long long cnt = 1; 
        long long prev = 0; 
        for(long long i = 1; i < n; i++) {
            if(nums[i] != nums[i - 1]) {
                ans += (i - prev); 
                
            } else {
               prev = i; 
            }
        }
        return ans; 
    }
};