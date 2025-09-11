class Solution {
public:
    int countAsterisks(string s) {
        stack<char> st;
        int ans = 0;
        for(auto x : s){
            if(st.empty() && x == '*')
            ans++;
            else if(st.empty() && x == '|')
            st.push(x);
            else if(!st.empty() && x == '|')
            st.pop();
        }
        return ans;
    }
};