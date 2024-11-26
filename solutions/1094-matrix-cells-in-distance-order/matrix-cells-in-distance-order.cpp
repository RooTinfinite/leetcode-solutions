class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        vector<vector<int>> ans;
        vector<pair<int, pair<int,int>>> v;

        for(int i = 0; i < rows; ++i){
            for(int j = 0; j < cols; ++j){
                v.push_back({abs(i - rCenter) + abs(j - cCenter), {i, j}});
            }
        }

        sort(v.begin(), v.end());

        for(auto &i : v){
            ans.push_back({i.second.first, i.second.second});
        }
        return ans;
    }
};