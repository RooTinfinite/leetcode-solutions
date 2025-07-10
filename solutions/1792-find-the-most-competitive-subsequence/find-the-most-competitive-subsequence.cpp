class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        deque<int> queue;
        int additionalCount = nums.size() - k;
        for (int i = 0; i < nums.size(); i++) {
            while (!queue.empty() && queue.back() > nums[i] &&
                   additionalCount > 0) {
                queue.pop_back();
                additionalCount--;
            }
            queue.push_back(nums[i]);
        }
        vector<int> result;
        for (int i = 0; i < k; i++) {
            result.push_back(queue.front());
            queue.pop_front();
        }
        return result;
    }
};