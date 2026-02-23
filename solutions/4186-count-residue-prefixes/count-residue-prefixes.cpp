class Solution {
public:
    int residuePrefixes(string s) {
        set<int> st;
        int n = s.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            st.insert(s[i]);
            if (st.size() == (i + 1) % 3) ans++;
            if (st.size() >= 3) return ans;
        }
        return ans;
    }
};