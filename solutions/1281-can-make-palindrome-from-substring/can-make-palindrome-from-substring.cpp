class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        int n = s.size();
        vector<bool> ans;
        vector<int> freq(26, 0);
        vector<vector<int>> st;
        for(int i=0;i<n;i++) {
            freq[s[i]-'a']++;
            st.push_back(freq);
        }
        int odd = 0;
        for(auto q: queries) {
            int l = q[0], h = q[1], k = q[2];
            odd = 0;
            for(int i=0;i<26;i++) {
                if(l>=1) odd += (st[h][i]-st[l-1][i])%2;
                else odd += st[h][i]%2;
            }
            int cnt = odd/2;
            if(cnt<=k) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};