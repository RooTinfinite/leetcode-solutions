class Solution {
public:
    int minimumSum(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        map<int,int> idx1, idx2;
        for (int i = 0; i < n; ++i) {
            if (idx1.find(nums1[i]) == idx1.end()) idx1[nums1[i]] = i;
            if (idx2.find(nums2[i]) == idx2.end()) idx2[nums2[i]] = i;
        }
        int best = INT_MAX;
        for (const auto &p : idx1) {
            auto it = idx2.find(p.first);
            if (it != idx2.end()) {
                int sum = p.second + it->second;
                if (sum < best) best = sum;
            }
        }
        return (best == INT_MAX) ? -1 : best;
    }
};