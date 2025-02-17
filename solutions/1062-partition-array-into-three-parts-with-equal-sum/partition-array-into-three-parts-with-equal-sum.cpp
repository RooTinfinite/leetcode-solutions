class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& arr) {
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3 != 0) return false; 
        int target = total / 3, sum = 0, count = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr[i];
            if (sum == target) {
                sum = 0;
                count++;
            }
            if (count == 2 && i < arr.size() - 1) return true;
        }        
        return false;
    }
};