class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<long long> suffixmin(n);
        suffixmin[n-1] = nums[n-1];
        for(int i = n -2 ; i >= 0 ; i--){
            suffixmin[i] = min((long long)nums[i],suffixmin[i+1]);
        }
        long long maxscore = LLONG_MIN;
        long long prefixsum = 0;
        for(int i = 0 ; i < n-1 ;i++){
            prefixsum += nums[i];
            long long score = prefixsum - suffixmin[i+1];
            if(score > maxscore){
                maxscore = score;
            }
        }
        return maxscore;
    }
};