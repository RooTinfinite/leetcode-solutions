class Solution {
public:
    int minSplitMerge(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<int> target = nums2;
        if (nums1 == nums2) return 0;

        queue<vector<int>> q;
        set<vector<int>> st;
        q.push(nums1);
        st.insert(nums1);
        int steps = 0;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto curr = q.front(); q.pop();
                if (curr == target) return steps;

                for (int l = 0; l < n; l++) {
                    for (int r = l; r < n; r++) {
                        vector<int> rem(curr.begin() + l, curr.begin() + r + 1);
                        vector<int> newli;
                        newli.insert(newli.end(), curr.begin(), curr.begin() + l);
                        newli.insert(newli.end(), curr.begin() + r + 1, curr.end());

                        for (int idx = 0; idx <= (int)newli.size(); idx++) {
                            vector<int> finalli = newli;
                            finalli.insert(finalli.begin() + idx, rem.begin(), rem.end());
                            if (!st.count(finalli)) {
                                st.insert(finalli);
                                q.push(finalli);
                            }
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    }
};