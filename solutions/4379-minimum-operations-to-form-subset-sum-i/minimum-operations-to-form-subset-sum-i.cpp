class Solution {
public:
    int minOperations(vector<int>& nums, int sum) {
        vector<long long int> dp(sum+1, INT_MAX);
        dp[0] = 0;
        for(auto it : nums){
            vector<int> options; 
            vector<long long int> toMake(sum + 1, INT_MAX);
            long long int curr = it;
            long long int steps = 0;
            while(curr <= sum){
                toMake[curr] = min(toMake[curr], steps);
                options.push_back(curr);
                steps++;
                curr *= 2;
            }
            curr = it;
            steps = 0;
            while(curr > 0){
                if(curr <= sum){
                    toMake[curr] = min(toMake[curr], steps);
                    if(find(options.begin(), options.end(), curr) == options.end()){
                        options.push_back(curr);
                    }
                }
                steps++;
                curr /= 2;
            }

            vector<long long int> tempDp = dp;
            for(int i = 0; i <= sum;i++){
                if(dp[i] == INT_MAX){
                    continue;
                }

                for(auto j : options){
                    if(i + j > sum){
                        continue;
                    }
                    if(toMake[j] == INT_MAX){
                        continue;
                    }
                    tempDp[i + j] = min(tempDp[i + j], dp[i] + toMake[j]);
                }
            }

            dp = move(tempDp);
            
        }
        if(dp[sum] == INT_MAX){
            return -1;
        }
        return dp[sum];
    }
};