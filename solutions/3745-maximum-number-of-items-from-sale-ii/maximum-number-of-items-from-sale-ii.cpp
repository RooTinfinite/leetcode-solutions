class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        long long minCost = 2e9, ans = 0;
        int maxF = 0;
        
        for (auto& it : items) {
            minCost = min(minCost, (long long)it[1]);
            maxF = max(maxF, it[0]);
        }

        vector<int> freq(maxF + 1, 0);
        for (auto& it : items) {
            freq[it[0]]++;
        }

        vector<long long> multiples(maxF + 1, 0);
        for (int i = 1; i <= maxF; i++) {
            if (!freq[i]) continue; // Skip if factor doesn't exist
            for (int j = i; j <= maxF; j += i) {
                multiples[i] += freq[j];
            }
        }

        vector<pair<long long, long long>> validMoves;
        for (auto& it : items) {
            long long limit = multiples[it[0]] - 1; 
            
            if (limit > 0 && it[1] < 2LL * minCost) {
                validMoves.push_back({it[1], limit});
            }
        }

        sort(validMoves.begin(), validMoves.end());
        
        for (auto& move : validMoves) {
            //if (budget < move.first) continue;
            
            long long take = min(move.second, budget / move.first);
            ans += take * 2;
            budget -= take * move.first;
        }

        ans += budget / minCost;
        
        return ans;
    }
};