class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> ctr;
        int sm = 0;

        for (int num : nums) {
            ctr[num]++;
            sm += num;}

        vector<int> cands;
        for (const auto& [num, count] : ctr) {
            cands.push_back(num);}

        sort(cands.rbegin(), cands.rend());

        for (int n : cands) {
            int d = (sm - n) / 2;
            int m = (sm - n) % 2;
            if (m == 0 && ctr.count(d) && (d != n || ctr[d] > 1)) {
                return n;}
        }
        return -1;}
};