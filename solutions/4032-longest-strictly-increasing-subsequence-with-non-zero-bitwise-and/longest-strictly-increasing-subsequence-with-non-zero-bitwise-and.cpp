class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i <= 30; i++) {
            vector<int> temp;

            // Filter numbers having the i-th bit set
            for (int num : nums) {
                if (num & (1 << i)) {
                    temp.push_back(num);
                }
            }

            if (temp.empty()) continue;

            // Compute LIS on filtered array
            vector<int> curr;
            curr.push_back(temp[0]);

            for (int j = 1; j < temp.size(); j++) {
                if (temp[j] > curr.back()) {
                    curr.push_back(temp[j]);
                } else {
                    int idx = lower_bound(curr.begin(), curr.end(), temp[j]) - curr.begin();
                    curr[idx] = temp[j];
                }
            }

            ans = max(ans, (int)curr.size());
        }

        return ans;
    }
};