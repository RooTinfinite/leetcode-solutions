class Solution {
public:
    int cal(const int &a, const int &b) {
        int xa = a / 100, ya = (a % 100) / 10, za = a % 10;
        int xb = b / 100, yb = (b % 100) / 10, zb = b % 10;

        return 100 * ((xa + xb) / 2) + 10 * ((ya + yb) / 2) + (za + zb) / 2;
    }
    
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        unordered_set<int> uset;

        for (auto &it : points) {
            uset.insert(it[0] * 100 + it[1] * 10 + it[2]);
        }
        
        int ans = 0;
        int t = 100 * target[0] + 10 * target[1] + target[2];
        
        while (!uset.contains(t)) {
            auto temp = uset;
            
            for (auto it1 = uset.begin(); it1 != uset.end(); it1++) {
                for (auto it2 = next(it1); it2 != uset.end(); it2++) {
                    temp.insert(cal(*it1, *it2));
                }
            }

            if (temp == uset) return -1;
            
            uset = temp;
            ans++;
        }

        return ans;
    }
};