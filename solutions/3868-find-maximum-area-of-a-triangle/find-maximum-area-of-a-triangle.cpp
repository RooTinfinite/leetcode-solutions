class Solution {
public:
    long long maxArea(vector<vector<int>> &coords) {
        int n = coords.size();

        unordered_map<int, set<int>> xMap, yMap;
        set<int> allX, allY;
        for(int i = 0; i < n; i++) {
            xMap[coords[i][0]].insert(coords[i][1]);
            yMap[coords[i][1]].insert(coords[i][0]);
            allX.insert(coords[i][0]);
            allY.insert(coords[i][1]);
        }

        long long ans = LLONG_MIN;
        for(auto &[x, ySet]: xMap) {
            if(ySet.size() < 2) continue;

            int minY = *ySet.begin();
            int maxY = *ySet.rbegin();
            int base = maxY - minY;

            int minX = *allX.begin();
            int maxX = *allX.rbegin();
            
            if(minX != x) ans = max(ans, 1LL * abs(x - minX) * base);
            if(maxX != x) ans = max(ans, 1LL * abs(x - maxX) * base);
        }

        for(auto &[y, xSet]: yMap) {
            if(xSet.size() < 2) continue;

            int minX = *xSet.begin();
            int maxX = *xSet.rbegin();
            int base = maxX - minX;

            int minY = *allY.begin();
            int maxY = *allY.rbegin();
            
            if(minY != y) ans = max(ans, 1LL * abs(y - minY) * base);
            if(maxY != y) ans = max(ans, 1LL * abs(y - maxY) * base);
        }

        return ans == LLONG_MIN ? -1 : ans;
    }
};