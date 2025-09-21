class Solution {
public:
    int minimumPartition(string s, int k) {
        for (int i = 0; i < s.size(); i++) {
            if (s[i] - '0' > k) return -1;
        }
        
        int cnt = 0;
        int i = 0;
        while (i < s.size()) {
            string res = "";
            while (i < s.size() && compare(res + s[i], k)) {
                res += s[i];
                i++;
            }
            cnt++;
        }
        return cnt;
    }

private:
    bool compare(const string& str, int k) {
        if (str.size() > to_string(k).size()) return false;
        if (str.size() < to_string(k).size()) return true;
        return str <= to_string(k);
    }
};