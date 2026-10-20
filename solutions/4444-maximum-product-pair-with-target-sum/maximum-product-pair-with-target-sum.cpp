class Solution {
public:
    vector<int> maxProductPair(vector<int>& nums, int target) {
        vector<int> ans{-1, -1};
        int best = INT_MIN;
        unordered_map<int, int> seen;  // value -> an index holding it
        for (int i = 0; i < nums.size(); i++) {
            int x = nums[i], y = target - x;
            if (x != y && seen.contains(y) && x * y > best) {
                best = x * y;
                ans = x > y ? vector<int>{i, seen[y]} : vector<int>{seen[y], i};  // larger value first
            }
            seen[x] = i;
        }
        return ans;
    }
};