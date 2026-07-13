class Solution {
public:
    int passwordStrength(string password) {
        unordered_set<char> s;
        int ans = 0;

        auto getScore = [&](char ch) -> int {
            if(ch >= 'a' && ch <= 'z') return 1;
            else if(ch >= 'A' && ch <= 'Z') return 2;
            else if(ch >= '0' && ch <= '9') return 3;
            else return 5;
        };

        for(auto ch : password) {
            if(!s.count(ch)) {
                ans += getScore(ch);
                s.insert(ch);
            }
        }

        return ans;
    }
};