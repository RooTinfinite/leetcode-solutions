class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        unsigned long long losses1 = 0;  // Bits 0-63
        unsigned long long losses2 = 0;  // Bits 64-99
        
        for (const auto& edge : edges) {
            if (edge[1] < 64) {
                losses1 |= (1ULL << edge[1]);
            } else {
                losses2 |= (1ULL << (edge[1] - 64));
            }
        }
        
        int champion = -1;
        for (int i = 0; i < n; i++) {
            bool hasLost = (i < 64) ? 
                (losses1 & (1ULL << i)) : 
                (losses2 & (1ULL << (i - 64)));
                
            if (!hasLost) {
                if (champion != -1) return -1;
                champion = i;
            }
        }
        
        return champion;
    }
};