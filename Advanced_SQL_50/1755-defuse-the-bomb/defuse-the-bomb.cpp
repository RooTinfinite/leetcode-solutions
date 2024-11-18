class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n, 0);
        if (k == 0) return result;
        
        if (k > 0) {
            int windowSum = accumulate(code.begin() + 1, code.begin() + k + 1, 0);
            result[0] = windowSum;
            for (int i = 1; i < n; i++) {
                windowSum += -code[i] + code[(i + k) % n];
                result[i] = windowSum;
            }
        } else {
            k = -k;
            int windowSum = accumulate(code.end() - k, code.end(), 0);
            result[0] = windowSum;
            for (int i = 1; i < n; i++) {
                windowSum += -code[(n - k + i - 1) % n] + code[i - 1];
                result[i] = windowSum;
            }
        }
        return result;
    }
};