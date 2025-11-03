class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        uint8_t MIN = nums[0];
        uint8_t MAX = nums[0];
        bitset<101> seen;

        for (uint8_t it : nums) {
            MIN = min(MIN, it);
            MAX = max(MAX, it);
            seen.set(it);
        }

        vector<int> res;
        for (uint8_t i = MIN; i <= MAX; ++i)
            if (!seen.test(i))
                res.push_back(i);

        return res;
    }
};