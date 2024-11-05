class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<long long> arr; // Use long long to handle large numbers
        for (int potion : potions) {
            arr.push_back(ceil(success / (double)potion)); // Ensure double division for accurate results
        }
        sort(arr.begin(), arr.end());

        vector<int> res;
        for (int spell : spells) {
            int l = 0, r = arr.size() - 1, M = 0;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (arr[m] <= spell) {
                    l = m + 1;
                    M = l;
                } else {
                    r = m - 1;
                }
            }
            res.push_back(M);
        }

        return res;
    }
};