class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int r = startPos[0] , c = startPos[1], re = homePos[0], ce = homePos[1], ans = 0;
        while(r < re) ans += rowCosts[++r];
        while(c < ce) ans += colCosts[++c];
        while(r > re) ans += rowCosts[--r];
        while(c > ce) ans += colCosts[--c];
        return ans;
        
    }
};