class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start >= 0 and start < arr.size() and arr[start] >= 0) {
            if (arr[start] == 0) {
                return true;
            }
            arr[start] = -arr[start];
            return canReach(arr, start + arr[start]) or
                   canReach(arr, start - arr[start]);
        }
        return false;
    }
};