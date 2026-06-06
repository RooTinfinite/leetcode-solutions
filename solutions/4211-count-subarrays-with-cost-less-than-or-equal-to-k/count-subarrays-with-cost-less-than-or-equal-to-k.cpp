class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        int n = (int)nums.size();
        deque<int> maxq, minq; // store indices

        long long res = 0;
        int l = 0;
        for (int r = 0; r < n; ++r) {
            while (!maxq.empty() && nums[maxq.back()] <= nums[r]) 
                maxq.pop_back();
            maxq.push_back(r);

            while (!minq.empty() && nums[minq.back()] >= nums[r]) 
                minq.pop_back();
            minq.push_back(r);

            while (l <= r && 1LL * (r - l + 1) * ( (long long)nums[maxq.front()] - nums[minq.front()] ) > k) {
                if (!maxq.empty() && maxq.front() == l) 
                    maxq.pop_front();
                if (!minq.empty() && minq.front() == l) 
                    minq.pop_front();
                ++l;
            }

            res += (r - l + 1);
        }

        return res;
    }
};