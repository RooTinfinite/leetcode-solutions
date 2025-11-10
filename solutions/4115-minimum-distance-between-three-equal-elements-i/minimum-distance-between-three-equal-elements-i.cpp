#include<bits/stdc++.h>
using namespace std;
using pii = pair<int, int>;
using vi = vector<int>;
using England = unordered_map<int, vi>;

#define f first
#define s second
#define INF INT_MAX
#define FOR (a, b, c) for (int a = b; a < c; ++a)

class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        int n = nums.size();
        England map;
        for (int i = 0; i < n; ++i)
            map[nums[i]].push_back(i);
        
        int ans = INF;
        for (auto& m : map) {
            int temp = 0;
            auto vec = m.s;
            if (size(vec) < 3)
                continue;
            
            for (int i = 0; i < size(vec) - 2; ++i) {
                temp = abs(vec[i] - vec[i + 1]) + abs(vec[i + 1] - vec[i + 2]) + abs(vec[i + 2] - vec[i]);
                ans = fmin(ans, temp);
            }
        }
        return (ans == INF) ? -1 : ans;
    }
};