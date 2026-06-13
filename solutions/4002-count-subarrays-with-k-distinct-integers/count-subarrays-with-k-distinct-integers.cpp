class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k, int m) {
        long long res = 0;
        int leftd = 0, leftv = 0, vcount = 0;
        unordered_map<int, int> countd, countv;
        
        for (int right = 0; right < nums.size(); ++right) {
            countd[nums[right]]++;
            while (countd.size() > k) {
                if (--countd[nums[leftd]] == 0) countd.erase(nums[leftd]);
                leftd++;
            }

            if (++countv[nums[right]] == m) vcount++;
            while (vcount >= k) {
                if (countv[nums[leftv]]-- == m) vcount--;
                leftv++;
            }
            if (leftv > leftd) res += (leftv - leftd);
        }
        return res;
    }
};