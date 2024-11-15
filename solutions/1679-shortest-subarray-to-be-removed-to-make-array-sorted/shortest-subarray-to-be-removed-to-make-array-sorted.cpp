class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int right = arr.size() - 1;
        
        while (right > 0 && arr[right] >= arr[right - 1]) {
            right--;
        }
        
        int ret = right;
        int left = 0;
        
        while (left < right && (left == 0 || arr[left - 1] <= arr[left])) {
            while (right < arr.size() && arr[left] > arr[right]) {
                right++;
            }
            
            ret = min(ret, right - left - 1);
            left++;
        }
        
        return ret;
    }
};