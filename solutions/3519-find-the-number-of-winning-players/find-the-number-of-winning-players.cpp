class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        int players[10][11] = {}, res = 0;
        bool seen[10] = {};
        for (auto& p : pick){
            if (++players[p[0]][p[1]] > p[0] && !seen[p[0]]){
                res++;
                seen[p[0]] = true;
            }
        }
        return res;
    }
};