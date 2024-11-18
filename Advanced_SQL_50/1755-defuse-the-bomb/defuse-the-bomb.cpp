class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int N = code.size();
        vector<int> res(N, 0);
        
        if (k == 0) return res;
        
        int l = 0;
        int cur_sum = 0;
        
        for (int r = 0; r < N + abs(k); r++) {
            cur_sum += code[r % N];
            
            if (r - l + 1 > abs(k)) {
                cur_sum -= code[l % N];
                l = (l + 1) % N;
            }
            
            if (r - l + 1 == abs(k)) {
                if (k > 0) {
                    res[(l - 1 + N) % N] = cur_sum;
                } else if (k < 0) {
                    res[(r + 1) % N] = cur_sum;
                }
            }
        }
        
        return res;
    }
};