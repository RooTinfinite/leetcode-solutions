class Solution {
public:
    int minLengthAfterRemovals(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            while (!st.empty() and s[i] != st.top()) {
                if (i >= s.size()) break;
                st.pop();
                i++;
            }
            if (i < s.size())
            st.push(s[i]);
        }
        return st.size();
    }
};