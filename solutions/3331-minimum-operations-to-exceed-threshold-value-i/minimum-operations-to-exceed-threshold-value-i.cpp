class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int operation = 0;
        for (int num : nums) {
            if (num < k) {
                operation++;
            }
        }
        return operation;
    }
};