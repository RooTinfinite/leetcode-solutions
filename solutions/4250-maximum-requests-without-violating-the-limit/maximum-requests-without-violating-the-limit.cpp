class Solution {
public:
    int maxRequests(vector<vector<int>>& r, int k, int window) {
        for (auto& v : r) swap(v[0], v[1]);
        sort(r.begin(), r.end());
        unordered_map<int, vector<int>> m;
        for (auto& v : r) m[v[1]].push_back(v[0]);
        int ans = 0;
        for (auto& [f,v] : m) {
            for (int l = 0, rr = 0, cur = 0; l < v.size(); ++l){
                while (rr < v.size() && v[rr] <= v[l] + window){
                    ++cur;
                    if (cur > k){
                        v[rr] = -1;
                        --cur;
                        ++ans;
                    }
                    ++rr;
                }
                cur -= v[l] != -1;
            }
        }
        return r.size() - ans;
    }
};