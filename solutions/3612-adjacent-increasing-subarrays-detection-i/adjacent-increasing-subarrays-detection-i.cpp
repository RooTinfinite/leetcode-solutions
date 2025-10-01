class Solution {
public:
    bool hasIncreasingSubarrays(const std::vector<int>& nums, int k) {
        auto mono = [&](int idx) -> bool {
            for (int i = idx; i < idx + k - 1; ++i) {
                if (nums[i] >= nums[i + 1]) return false;}
            return true;
        };

        for (int idx = 0; idx <= nums.size() - 2 * k; ++idx) {
            if (mono(idx) && mono(idx + k)) {
                return true; }
        }
        return false;}
};