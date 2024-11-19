class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int res = INT_MAX;
        long long curSum = 0;
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<>> minHeap;
        
        for (int r = 0; r < nums.size(); r++) {
            curSum += nums[r];
            
            if (curSum >= k) {
                res = min(res, r + 1);
            }
            
            // Find the min window ending at r
            while (!minHeap.empty() && curSum - minHeap.top().first >= k) {
                auto [prefix, endIdx] = minHeap.top();
                minHeap.pop();
                res = min(res, r - endIdx);
            }
            
            minHeap.push({curSum, r});
        }
        
        return res == INT_MAX ? -1 : res;
    }
};