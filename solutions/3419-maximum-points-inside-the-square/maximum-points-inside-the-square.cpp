#pragma GCC optimize("03", "unroll-loops")
class Solution {
public:
    int maxPointsInsideSquare(vector<vector<int>>& points, string s) {
        int n = points.size();
        //bas pos lena
        for (int i = 0; i < n; ++i) {
            points[i][0] = abs(points[i][0]);
            points[i][1] = abs(points[i][1]);
        }
        
        int left = 0;
        int right = 1e9;
        int ans_cp = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            unordered_map<char, int> mp;
            
            int checker = 1;
            
            for (int i = 0; i < n; ++i) {
                if (points[i][0] <= mid && points[i][1] <= mid) {
                    mp[s[i]]++;
                }
            }
            
            for (auto it : mp) {
                if (it.second > 1) {
                    checker = 0;
                    break;
                }
            }

            if (checker==1) {
                ans_cp = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        
        int ans = 0;
        
        for (int i = 0; i < n; i++) {
            if (points[i][0] <= ans_cp && points[i][1] <= ans_cp) {
                ans++;
            }
        }
        
        return ans;
    }
};

auto init = [](){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 'c';
}();