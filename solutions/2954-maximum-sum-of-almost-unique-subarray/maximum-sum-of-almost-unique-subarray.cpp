class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        int n = nums.size();
        long long maxSum = 0;
        long long currSum = 0;
        unordered_map<int,int> T;
        int left = 0;
        for(int right = 0; right < n; right++){
            T[nums[right]]++;
           currSum += (long long) nums[right];
            while((right - left + 1) == k){
              if(T.size() >= m){
                 maxSum = max(currSum,maxSum);
              }  
               currSum -= nums[left];
               T[nums[left]]--;
               if(T[nums[left]] == 0){
                T.erase(nums[left]);
               }
               left++;
            }
        }
      return maxSum;
    }
};