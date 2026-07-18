class Solution {
public:
    vector<int> maximumMEX(vector<int>& nums) {
        int mex = 0;
        int n = nums.size();
        int N = 1e5 + 2;
        vector<int> freq(N, 0);
        vector<int> Suff(n, -1);
        for (int i = n - 1; i >= 0; i--) {
            freq[nums[i]]++;
            while (freq[mex] > 0) {
                mex++;
            }
            Suff[i] = mex;
        }

        
        int ind = 0;
        vector<int> Ans;
        while (ind < n) {
            if (Suff[ind] == 0) {
                while (ind < n) {
                    Ans.push_back(0);
                    ind++;
                }
            } else {
                int C = 0;
                int limit = Suff[ind];
                unordered_map<int, int> Map;
                while (C < limit) {
                    if (nums[ind] < limit && !Map.count(nums[ind])) {
                        C++;
                        Map[nums[ind]]++;
                    }
                    ind++;
                }
                Ans.push_back(limit);
            }
        }
        return Ans;
    }
};