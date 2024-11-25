class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int i = 0, j = 0;
        while (i < pushed.size()) {
            st.push(pushed[i]);
            while (!st.empty() && j < popped.size() && popped[j] == st.top()) {
                st.pop();
                j++;
            }
            i++;
        }
        return st.empty() ? true : false;
    }
};