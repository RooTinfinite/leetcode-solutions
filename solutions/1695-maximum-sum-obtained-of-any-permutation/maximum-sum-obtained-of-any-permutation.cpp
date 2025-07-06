class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n = nums.size();
        const int mod{1000000007};
        std::vector<int> line(n + 1);
        for (const std::vector<int>& vec : requests) {
            ++line[vec[0]];
            --line[vec[1] + 1];
        }

        for (int i{1}; i < n; ++i) {
            line[i] += line[i - 1];
        }

        std::sort(line.begin(), line.end(), std::greater<>{});
        std::sort(nums.begin(), nums.end(), std::greater<>{});

        int res{};
        for (int i{}; i < n; ++i) {
            res = (res + (static_cast<long long>(line[i]) * nums[i]) % mod) % mod;
        }

        return res;
    }
};