class Solution {
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        vector<int> curr(n, 0), prev(n, 0);

        for (int day = k - 1; day >= 0; --day) {
            for (int city = 0; city < n; ++city) {

                int move = 0;
                for (int i = 0; i < n; ++i) {
                    move = max(move, prev[i] + travelScore[city][i]);}

                int stay = max(curr[city], prev[city] + stayScore[day][city]);
                curr[city] = max(move, stay);}
                
            prev.swap(curr);}

        return *max_element(prev.begin(), prev.end());}
};