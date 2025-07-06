class Solution {
public:
    double trimMean(vector<int>& arr) {
        int n = arr.size(), skip = n / 20;
        auto start = arr.begin() + skip, end = arr.begin() + n - skip;
        nth_element(arr.begin(), start, arr.end());
        nth_element(start, end, arr.end());
        return accumulate(start, end, 0.0) / (n - skip * 2);
    }
};