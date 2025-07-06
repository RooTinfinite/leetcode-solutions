class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        int count = 0;
        for(int i = 0, n = arr.size() - m; i < n; ++i){
            if(arr[i] == arr[i + m]) ++count;
            else count = 0;
            if(count == m * (k - 1)) return true;
        }
        return false;
    }
};