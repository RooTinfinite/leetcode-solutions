class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        vector<int> freq(100001, 0);
        long long distinctsum = 0;

        int left = 0;
        int ans = INT_MAX;

        for (int right = 0; right < nums.size(); right++) {
            int val = nums[right];

            if (freq[val] == 0) {
                distinctsum += val;
            }
            freq[val]++;

            while (distinctsum >= k) {
                ans = min(ans, right - left + 1);

                int leftval = nums[left];
                freq[leftval]--;

                if (freq[leftval] == 0) {
                    distinctsum -= leftval;
                }
                left++;
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};