class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& arr, int freeStart, int freeEnd) {

        sort(arr.begin(), arr.end());

        vector<vector<int>> temp;

        for (auto &brr : arr) {
            if (temp.empty() || temp.back()[1] + 1 < brr[0]) {
                temp.push_back(brr);
            } else {
                temp.back()[1] = max(temp.back()[1], brr[1]);
            }
        }

        vector<vector<int>> res;

        for (auto &brr : temp) {
            int s = brr[0];
            int e = brr[1];

            if (e < freeStart || s > freeEnd) {
                res.push_back({s, e});
            } else {
                if (s < freeStart)
                    res.push_back({s, freeStart - 1});

                if (e > freeEnd)
                    res.push_back({freeEnd + 1, e});
            }
        }

        return res;
    }
};