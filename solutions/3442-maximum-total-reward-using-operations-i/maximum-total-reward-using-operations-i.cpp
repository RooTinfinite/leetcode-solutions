class Solution {
public:
    int maxTotalReward(vector<int>& rewardValues) {
        int n = rewardValues.size();
        sort(rewardValues.begin(), rewardValues.end());
        int maxPossibleScove = rewardValues.back() * 2;
        
        vector<bool> preDP(maxPossibleScove + 1), curDP(maxPossibleScove + 1);
        preDP[0] = true;
        for(int i = 0; i < rewardValues.size(); i++) {
            for(int j = 0; j < rewardValues[i]; j++) {
                curDP[j + rewardValues[i]] = curDP[j + rewardValues[i]] | preDP[j];
            }
            for(int j = 0; j < curDP.size(); j++) {
                preDP[j] = preDP[j] | curDP[j];
                curDP[j] = false;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < preDP.size(); i++) {
            if(preDP[i]) {
                ans = max(ans, i);
            }
        }
        return ans;
    }
};