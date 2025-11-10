class Solution {
public:
    long solve(vector<int>& nums, int k) {
        int n = size(nums);
        vector<vector<long>> dp(k + 1, vector<long>(n + 1, 0)); // dp[i][k] = result for  up to k subarrays for nums upto not includeing i. So dp[k][n] is final ans
        //the first row dp[0] is already complete, 0 subarrays = subresult is 0
        // dp[k][i] >= dp[k][i - 1] because as we add more els. the subresult will always get better or at least not get worse
        // note that adding to a subarray will never decrease it, as we get more els. max will only increase and min will only decrease
        // any subarray should start and end with min and max or vice versa
        // (proof of above) if it doesn't start or end with min or max we can just cut off the elements from the front or back until we get to min or max and the curr. subarray will not be affected and we can give the elements to other subarrays
        for (int cnt = 1; cnt <= k; ++cnt) {
            long minComp = LONG_MIN, maxComp = LONG_MIN; // minimum/maximum component = max(prevRow[i] -/+ nums[i]), nums[ind] is added subtracted to them
            auto& prevRow = dp[cnt - 1];
            for (int ind = 0; ind < n; ++ind) {
                dp[cnt][ind + 1] = dp[cnt][ind];

                // for (int i = ind; i >= 0; --i) minComp = max(minComp, prevRow[i] - nums[i]) <--- shows what minComp is
                // if we get a new maximum for minComp then nums[i] must be minimum in [i, ind]
                // because prevRow[i] decreases/stays same as i decreases
                // minComp is used assuming that nums[ind] is a maximum
                // this also depends on the subresult, any given nums[i] could be a new minimum
                // but if prevRow[i] is too small we just ignore it. because even though we could find a new minimum, the term (prevRow[i] - nums[i]) is lower than the best (prevRow[j] - nums[j])
                // and since we 
                // and so we consider minComp + nums[ind] = prevRow[i] - nums[i] + nums[ind] = prevRow[i] + (nums[ind] - nums[i])
                minComp = max(minComp, prevRow[ind] - nums[ind]);

                // same concept as minComp, except since we are adding, we are finding new maximums
                maxComp = max(maxComp, prevRow[ind] + nums[ind]);
                long currIsMax = minComp + nums[ind];
                long currIsMin = maxComp - nums[ind];

                long best = max(currIsMax, currIsMin);
                if (best > dp[cnt][ind + 1]) dp[cnt][ind + 1] = best;
            }
        }
        return dp[k][n];
    }
    long maximumScore(vector<int>& nums, int k) { // long is the same as long long

        //Use standard DP
        int n = size(nums);

        int minInd = min_element(begin(nums), end(nums)) - begin(nums); // the min ind MUST be the start or end for one subarray. use as anchor
        vector<int> standard, reversed;
        for (int ind = minInd, times = 0; times < n; ++times, ++ind) standard.push_back(nums[(ind + n) % n]); // when min ind is the start
        for (int ind = minInd, times = 0; times < n; ++times, --ind) reversed.push_back(nums[(ind + n) % n]); // when min ind is the end, reverse everything and it is the start

        return max(solve(standard, k), solve(reversed, k));
    }
};