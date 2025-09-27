class Solution {
public:
    vector<long long> mostFrequentIDs(vector<int>& nums, vector<int>& freq) {
        priority_queue<pair<long long, int>> pq; 
        unordered_map<int, long long> cnt; 
        vector<long long> ans; 
        for (int i = 0, n = nums.size(); i < n; ++i) {
            int x = nums[i], f = freq[i]; 
            cnt[x] += f; 
            while (pq.size() && cnt[pq.top().second] != pq.top().first) pq.pop(); 
            pq.emplace(cnt[x], x); 
            ans.push_back(pq.top().first); 
        }
        return ans; 
    }
};