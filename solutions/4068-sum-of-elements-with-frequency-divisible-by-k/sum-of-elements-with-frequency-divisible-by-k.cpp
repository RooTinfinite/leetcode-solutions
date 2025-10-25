class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        unordered_set<int> s(nums.begin(), nums.end());
        int count = 0;

        for (int i : s) {
            int cnt = count_if(nums.begin(), nums.end(), [&](int x){ return x == i; });
            if (cnt % k == 0) count += i * cnt;
        }

        return count;
    }
};