class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> result(n);
        
        if (k == 0) {
            return result;
        }
        
        if (k > 0) {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= k; j++) {
                    sum += code[(i + j) % n];
                }
                result[i] = sum;
            }
        } else {
            for (int i = 0; i < n; i++) {
                int sum = 0;
                for (int j = 1; j <= -k; j++) {
                    sum += code[(i - j + n) % n];
                }
                result[i] = sum;
            }
        }
        
        return result;
    }
};