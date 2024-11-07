class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> ans(32, 0);
        
        for(int x : candidates) {
            find(x, ans);
        }
        
        int res = 0;
        for(int i = 0; i < 32; i++) {
            res = max(res, ans[i]);
        }
        
        return res;
    }
    
    void find(int n, vector<int>& ans) {
        int j = 31;
        
        while(n > 0) {
            int a = (n & 1);
            ans[j] += a;
            n >>= 1;
            j--;
        }
    }
};