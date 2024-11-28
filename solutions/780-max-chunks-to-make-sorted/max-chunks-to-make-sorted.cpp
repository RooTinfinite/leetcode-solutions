class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        stack<int> st;
        for (int num : arr) {
            if(! st.empty() && num < st.top()){
                int top = st.top();
                while (!st.empty() && num < st.top()) {
                    st.pop();
                }
                st.push(top);
            }
            else{
                st.push(num);
            }
        }
        return st.size();
    }
};