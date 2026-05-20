class Solution {
public:
    int alternatingXOR(vector<int>& nums, int t1, int t2) {
        long long mod = 1e9 + 7;
        unordered_map<int, long long> m1, m2;  // m1: odd positions, m2: even positions
        int cur = 0;  // prefix XOR
        long long d1 = 0, d2 = 0;
        m2[0] = 1;  // base case: empty prefix at even position
        
        for (int x : nums) {
            cur ^= x;
            // Count subarrays ending here with correct XOR targets
            d1 = m2.count(cur ^ t1) ? m2[cur ^ t1] : 0;
            d2 = m1.count(cur ^ t2) ? m1[cur ^ t2] : 0;
            
            // Update maps for next iteration
            m1[cur] = (m1[cur] + d1) % mod;
            m2[cur] = (m2[cur] + d2) % mod;
        }
        
        return (d1 + d2) % mod;
    }
};