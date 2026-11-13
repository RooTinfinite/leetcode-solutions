class Solution {
public:
    int maximumLength(vector<int>& nums, int k) {
        // freq[k]: store the longest subsequence ending with num k
        // we can only extend the freq[k] when the previous num is k apart
        // thus freq[k] = max(freq[k], freq[prev_num] + 1)
        std::vector<int> freq(k);
        int res{1};
        for (auto num : nums) {
            freq[num % k] = max(freq[num % k], freq[(k - num % k) % k] + 1);
            res = max(res, freq[num % k]);
        }
        return res;
    }
};