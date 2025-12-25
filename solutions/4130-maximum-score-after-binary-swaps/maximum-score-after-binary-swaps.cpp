class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {
        long long sum = 0;
        priority_queue<int> pq;
        for (int i = 0; i < (int)nums.size(); i++) {
            if (s[i] == '1') {
                if (!pq.empty() && pq.top() > nums[i]) {
                    sum += pq.top();
                    pq.pop();
                } else {
                    sum += nums[i];
                    continue;
                }
            }
            pq.push(nums[i]);
        }
        return sum;
    }
};