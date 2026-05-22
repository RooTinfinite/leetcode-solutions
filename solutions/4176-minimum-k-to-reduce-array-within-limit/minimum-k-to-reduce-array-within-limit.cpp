class Solution {
public:
    int nonPositive(const std::vector<int>& a, int k) {
        int result = 0;
        for (int x : a)
            result += (x + k - 1) / k;
        return result;
    }

    int minimumK(std::vector<int>& nums) {
        // Filter <= 0
        std::vector<int> a;
        a.reserve(nums.size());
        for (int x : nums)
            if (x > 0) 
                a.push_back(x);
        if (a.empty()) 
            return 0;

        int l = 1, r = std::max(*max_element(a.begin(), a.end()), (int)a.size());
        while (l < r) {
            int m = l + (r - l) / 2;
            long long mm = (long long)m * (long long)m;
            if (nonPositive(a, m) <= mm)
                r = m;
            else
                l = m + 1;
        }
        return l;
    }
};