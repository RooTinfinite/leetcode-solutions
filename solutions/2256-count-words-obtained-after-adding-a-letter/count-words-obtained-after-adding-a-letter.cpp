class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& target) {
        unordered_set<int> st;
        for (string& word :startWords) {
            int temp = 0;
            for (char ch : word) {
                temp |= (1 << (ch - 'a'));
            }
            st.insert(temp);
        }
        int ans = 0;
        for (string& word :target) {
            int temp = 0;
            for (char ch :word) {
                temp |= (1 << (ch - 'a'));
            }
            for (char ch : word) {
                int newtemp = temp & ~(1 << (ch - 'a'));
                if (st.find(newtemp) != st.end()) {
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};