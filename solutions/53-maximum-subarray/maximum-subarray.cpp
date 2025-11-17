class Solution {
private:
    vector<int> numsArray;

public:
    int maxSubArray(vector<int>& nums) {
        numsArray = nums;
        // Our helper function is designed to solve this problem for
        // any array - so just call it using the entire input!
        return findBestSubarray(0, numsArray.size() - 1);
    }
    int findBestSubarray(int left, int right) {
        // Base case - empty array.
        if (left > right) {
            return INT_MIN;
        }
        int mid = (left + right) / 2;
        int curr = 0;
        int bestLeftSum = 0;
        int bestRightSum = 0;
        // Iterate from the middle to the beginning.
        for (int i = mid - 1; i >= left; i--) {
            curr += numsArray[i];
            bestLeftSum = max(bestLeftSum, curr);
        }
        // Reset curr and iterate from the middle to the end.
        curr = 0;
        for (int i = mid + 1; i <= right; i++) {
            curr += numsArray[i];
            bestRightSum = max(bestRightSum, curr);
        }
        // The bestCombinedSum uses the middle element and the best
        // possible sum from each half.
        int bestCombinedSum = numsArray[mid] + bestLeftSum + bestRightSum;
        // Find the best subarray possible from both halves.
        int leftHalf = findBestSubarray(left, mid - 1);
        int rightHalf = findBestSubarray(mid + 1, right);
        // The largest of the 3 is the answer for any given input array.
        return max(bestCombinedSum, max(leftHalf, rightHalf));
    }
};