class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = 0, min = INT_MAX;
        for (int x : nums) {
            sum += x;
            min = std::min(min, x);
        }
        return sum - nums.size() * min;
    }
};