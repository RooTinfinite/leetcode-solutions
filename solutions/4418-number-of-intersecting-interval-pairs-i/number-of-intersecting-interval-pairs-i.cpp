class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& nums) {
        priority_queue<int, vector<int>, greater<>> pq;
        sort(nums.begin(), nums.end());
        pq.push(nums[0][1]);
        long long int sol = 0;
        int n = nums.size();
        for(int i= 1; i < n; i++){
            while(!pq.empty() && pq.top() < nums[i][0]){
                pq.pop();
            }
            sol += pq.size();
            pq.push(nums[i][1]);
        }
        return sol;
    }
};