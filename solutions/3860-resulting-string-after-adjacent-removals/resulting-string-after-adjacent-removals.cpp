class Solution {
public:
    string resultingString(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if(!st.empty() && (abs(s[i] - st.top()) == 1 || abs(s[i] - st.top()) == 25)){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        string ans;
        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};