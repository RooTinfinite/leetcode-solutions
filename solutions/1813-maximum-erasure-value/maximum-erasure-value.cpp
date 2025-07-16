class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size(), result = 0, start = 0;
        unordered_map<int, int> lastIndexMap;
        vector<int> prefixSum(n + 1, 0);

        for (int end = 0; end < n; end++) {
            int currentElement = nums[end];
            prefixSum[end + 1] = prefixSum[end] + currentElement;
            if (lastIndexMap.find(currentElement) != lastIndexMap.end()) {
                start = max(start, lastIndexMap[currentElement] + 1);
            }
            // update result with maximum sum found so far
            result = max(result, prefixSum[end + 1] - prefixSum[start]);
            lastIndexMap[currentElement] = end;
        }
        return result;
    }
};