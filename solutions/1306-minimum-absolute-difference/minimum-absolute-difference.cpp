class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) { 
        // Sort the original array 
        sort(arr.begin(), arr.end());
        vector<vector<int>> answer;

        // Initialize minimum difference as a huge integer in order not
        // to miss the absolute difference of the first pair. 
        int minPairDiff = INT_MAX;

        // Traverse the sorted array and calcalute the minimum absolute difference.
        for (int i = 0; i < arr.size() - 1; ++i) {
            minPairDiff = min(minPairDiff, arr[i + 1] - arr[i]);
        }

        // Traverse the sorted array and check every pair again, if 
        // the absolute difference equals the minimum difference, add 
        // this pair to the answer list.
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i + 1] - arr[i] == minPairDiff) {
                answer.push_back({arr[i], arr[i + 1]});
            }
        }

        return answer;
    }
};