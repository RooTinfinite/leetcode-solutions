class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        int ctr = 0;
        vector<int> even(n + 1, 0), odd(n + 1, 0);

        for (int i = 0; i < n; i++) {
            if (nums[i] & 1) {
                odd[i + 1] += odd[i] + 1;
                even[i + 1] += even[i];
            } else {
                even[i + 1] += even[i] + 1;
                odd[i + 1] += odd[i];
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= i; j++) {
                int ev_cnt = even[i + 1] - even[j];
                int od_cnt = odd[i + 1] - odd[j];
                if (od_cnt > 0)
                    if (1LL * ev_cnt * b <= 1LL * od_cnt * a)
                        ctr++;
            }
        }
        return ctr;
    }
};