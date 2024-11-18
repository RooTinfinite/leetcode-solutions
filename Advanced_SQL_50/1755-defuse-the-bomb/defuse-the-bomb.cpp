class Solution {
public:
    vector<int> decrypt(vector<int>& circ, int k) {
        int n = circ.size();
        vector<int> ans(n);
        
        if (k == 0) return ans;
        
        int wsum = 0;
        if (k > 0) {
            // Calculate initial window sum
            for (int i = 0; i < k; i++) {
                wsum += circ[i + 1];
            }
            
            // Sliding window
            ans[0] = wsum;
            for (int i = 1; i < n; i++) {
                wsum = wsum - circ[i] + circ[(i + k) % n];
                ans[i] = wsum;
            }
        } else {
            k = -k;
            // Calculate initial window sum
            for (int i = 0; i < k; i++) {
                wsum += circ[n - k + i];
            }
            
            // Sliding window
            ans[0] = wsum;
            for (int i = 1; i < n; i++) {
                wsum = wsum - circ[(n - k + i - 1) % n] + circ[i - 1];
                ans[i] = wsum;
            }
        }
        
        return ans;
    }
};
