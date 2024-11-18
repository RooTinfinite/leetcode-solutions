class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n);

        if (k == 0) return result;

        int windowSum = 0; int start = (k > 0) ? 1 : n + k; int end = (k > 0) ? k : n - 1;
        for (int i = start; i <= end; i++) {
            windowSum += code[i % n];
        }
        for (int i = 0; i < n; i++) {
            result[i] = windowSum;
            windowSum -= code[(start + i) % n];
            windowSum += code[(end + i + 1) % n];
        }
        
        return result;
    }
};