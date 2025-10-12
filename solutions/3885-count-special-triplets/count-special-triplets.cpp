class Solution {
    const int MOD = 1e9 + 7;
public:
    int specialTriplets(vector<int>& nums) {
        int n = nums.size();
        
        unordered_map<long long, long long> left, right;
        for (int i = 0; i < n; i++)
            right[nums[i]]++;
        
        long long result = 0;
        for (int j = 0; j < n; ++j) {
            right[nums[j]]--;
            int val = 2 * nums[j];
            long long lval = left[val];
            long long rval = right[val];

            result = (result + (lval * rval) % MOD) % MOD;

            left[nums[j]]++;
        }
        
        return (result);
    }
};