class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int currentWinner = arr[0];
        int count = 0;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] > currentWinner) {
                currentWinner = arr[i];
                count = 1;
            } else {
                count++;
            }
            if (count == k) {
                return currentWinner;
            }
        }
        return currentWinner;
    }
};