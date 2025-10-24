class Solution {
public:
    int distinctPoints(string s, int k) {
        int n = s.size();

        vector<pair<int,int>> pref(n+1, {0, 0});
        for(int i = 0;i < n;i++) {
            pref[i+1] = pref[i];
            if(s[i] == 'U') pref[i+1].second++;
            if(s[i] == 'D') pref[i+1].second--;
            if(s[i] == 'L') pref[i+1].first--;
            if(s[i] == 'R') pref[i+1].first++;
        }

        vector<pair<int,int>> suff(n+1, {0, 0});
        for(int i = n-1;i >=0;i--) {
            suff[i] = suff[i+1];
            if(s[i] == 'U') suff[i].second++;
            if(s[i] == 'D') suff[i].second--;
            if(s[i] == 'L') suff[i].first--;
            if(s[i] == 'R') suff[i].first++;
        }

        set<pair<int, int>> st;

        for(int i = 0;i + k <= n;i++) {
            st.insert({pref[i].first + suff[i+k].first, pref[i].second + suff[i+k].second});
        }

        return st.size();
    }
};