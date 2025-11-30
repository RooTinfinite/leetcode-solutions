class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int, int> mp;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            mp[nums[i]] = i;
        }

        int minDist = INT_MAX;

        for (int i = 0; i < n; i++) {
            int r = reverseNum(nums[i]);
            if (mp.count(r) && i < mp[r]) {
                minDist = min(minDist, mp[r] - i);
            }
        }

        return minDist == INT_MAX ? -1 : minDist;
    }

private:
    int reverseNum(int x) {
        int rev = 0;
        while (x > 0) {
            rev = rev * 10 + (x % 10);
            x /= 10;
        }
        return rev;
    }
};