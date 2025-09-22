const vector<int> PRIMES = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
const int MOD = 1e9+7;

typedef long long int ll;

class Solution {
    vector<vector<int>> dp;
    
    ll ConvertFromMask (int mask) {
        ll result = 1;
        
        for (int j = 0; j < PRIMES.size(); j ++) {
            if (mask & (1 << j)) result *= PRIMES[j];
        }
        return result;
    }
    
    int ConvertToMask (ll X) {
        int mask = 0;
        
        for (int j = 0; j < PRIMES.size(); j ++) {
            if (X % PRIMES[j] == 0) {
                X /= PRIMES[j];
                mask |= (1 << j);
            }
        }
        return mask;
    }
    
    int CountSubsets (int ind, int mask, const vector<int>& arr) {
        int n = arr.size();
        
        if (mask == 0) return 1;  
        if (ind == n) return 0;
        
        int &ans = dp[ind][mask];
        if (ans != -1) return ans;
        
        ll X = ConvertFromMask (mask);
        
        ans = CountSubsets (ind+1, mask, arr);
        if (X % arr[ind] == 0)
            ans = (ans + CountSubsets (ind+1, ConvertToMask (X / arr[ind]), arr)) % MOD;
        
        return ans;
    }
    
public:
    int squareFreeSubsets(vector<int>& nums) {
        vector<int> nums_but_1;
        int ones = 0;
        
        for (auto i : nums) {
            if (i == 1) ones ++;
            else nums_but_1.push_back(i);
        }
        
        dp.clear();
        int n = nums_but_1.size();
        dp.resize(n, vector<int>(1025, -1));
                    
        long long non_empty_one_subsets = 1;
        while (ones --) non_empty_one_subsets = (non_empty_one_subsets * 2) % MOD;
        non_empty_one_subsets = (non_empty_one_subsets - 1 + MOD) % MOD;
        
        long long non_empty_other_subsets = 0;
        for (int mask = 1; mask < 1024; mask ++) {
            non_empty_other_subsets = (non_empty_other_subsets + CountSubsets(0, mask, nums_but_1)) % MOD;
        }
        
        long long result = (non_empty_one_subsets + non_empty_other_subsets) % MOD;
        result = (result + (non_empty_other_subsets * non_empty_one_subsets) % MOD) % MOD;
        
        return result;
    }
};