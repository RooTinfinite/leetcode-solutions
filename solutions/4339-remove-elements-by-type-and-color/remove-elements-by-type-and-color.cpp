class Solution {
public:
    bool canRemoveAll(vector<int>& types, vector<int>& colors,
                      vector<int>& groupSize) {

        vector<array<int, 3>> st;

        int n = types.size();

        for (int i = 0; i < n; i++) {
            int t = types[i];
            int c = colors[i];

            if (st.empty() || st.back()[0] != t ||
                               st.back()[1] != c) {
                st.push_back({t, c, 1});
            }
            else {
                st.back()[2]++;
            }

            if (st.back()[2] == groupSize[t]) {
                st.pop_back();
            }
        }

        return st.empty();
    }
};