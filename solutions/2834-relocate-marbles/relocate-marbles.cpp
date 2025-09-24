class Solution {
public:
    vector<int> relocateMarbles(vector<int>& v, vector<int>& a, vector<int>& b) {
        unordered_set<int> st(v.begin(),v.end());
        for(int i = 0; i < a.size(); i += 1) {
            if(st.count(a[i])) {
                st.erase(a[i]);
                st.insert(b[i]);
            }
        }
        vector<int> ans(st.begin(),st.end());
        sort(ans.begin(),ans.end());
        return ans;
    }
};