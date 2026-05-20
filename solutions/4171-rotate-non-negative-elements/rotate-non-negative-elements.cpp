class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: Extract all non-negative elements
        vector<int> arr;
        for (int x : nums) {
            if (x >= 0) arr.push_back(x);
        }

        int m = arr.size();
        if (m == 0) return nums;  // no non-negative elements to rotate

        // Step 2: Normalize k
        k %= m;

        // Step 3: Left rotate arr by k -> store in brr
        vector<int> brr(m);
        for (int i = 0; i < m; i++) {
            int newIndex = i - k;
            if (newIndex < 0) newIndex += m;
            brr[newIndex] = arr[i];
        }

        // Step 4: Put rotated values back into original non-negative positions
        int idx = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] >= 0) {
                nums[i] = brr[idx++];
            }
        }

        return nums;
    }
};