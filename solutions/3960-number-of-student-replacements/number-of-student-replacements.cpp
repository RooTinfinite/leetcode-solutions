class Solution {
public:
    int totalReplacements(vector<int>& ranks) {
        int ans=0;
        int best=ranks[0];
        int n=ranks.size();

        for(int i=1;i<n;i++){
            if(ranks[i]<best){
                best=ranks[i];
                ans++;
            }
        }
        return ans;
    }
};