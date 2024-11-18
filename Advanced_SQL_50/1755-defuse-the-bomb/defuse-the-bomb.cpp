class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n);

        if (k == 0) return result;

        int wSum = 0; int start = (k > 0) ? 1 : n + k; int end = (k > 0) ? k : n - 1;
        for (int i = start; i <= end; i++) {
            wSum += code[i % n];
        }
        for (int i = 0; i < n; i++) {
            result[i] = wSum;
            wSum -= code[(start + i) % n];
            wSum += code[(end + i + 1) % n];
        }
        
        return result;
    }
};