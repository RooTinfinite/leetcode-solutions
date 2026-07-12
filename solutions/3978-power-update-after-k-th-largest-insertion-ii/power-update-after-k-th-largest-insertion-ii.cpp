class Solution {
private:
    vector<int> segTree;
    void updateTree(int idx, int i, int l, int r){        
        if (l == r){
            segTree[i]++;
            return;
        }

        int mid = l + ((r - l) >> 1);
        if (idx <= mid){
            updateTree(idx, 2 * i + 1, l, mid);
        }
        else{
            updateTree(idx, 2 * i + 2, mid + 1, r);
        }
        segTree[i] = segTree[2 * i + 1] + segTree[2 * i + 2];
    }

    int queryTree(int k, int i, int l, int r){
        if (l == r){
            return l;
        }

        int mid = l + ((r - l) >> 1);
        if (k <= segTree[2 * i + 1]){
            return queryTree(k, 2 * i + 1, l, mid);
        }

        return queryTree(k - segTree[2 * i + 1], 2 * i + 2, mid + 1, r);
    }

public:
    vector<int> powerUpdate(vector<int>& nums, int p, vector<vector<int>>& queries) {
        vector<int> vals = nums;

        for (auto& q : queries){
            vals.push_back(q[0]);
        }

        sort(vals.begin(), vals.end());

        vals.erase(unique(vals.begin(), vals.end()), vals.end());
        int m = vals.size();
        segTree.assign(4 * m, 0);

        auto getId = [&](int& x) -> int
        {
            return lower_bound(vals.begin(), vals.end(), x) - vals.begin();
        };

        for (auto& i : nums){
            updateTree(getId(i), 0, 0, m - 1);
        }

        const int MOD = 1e9 + 7;
        auto powMOD = [&](auto& self, const int& base, int exponent) -> long long
        {
            if (exponent == 0){
                return 1;
            }

            long long half = self(self, base, exponent >> 1);
            long long ans = (half * half) % MOD;
            return exponent & 1 ? ans * base % MOD : ans;
        };

        vector<int> ans;
        for (auto& q : queries){
            updateTree(getId(q[0]), 0, 0, m - 1);
            int order = segTree[0] - q[1] + 1;
            int idx = queryTree(order, 0, 0, m - 1);
            
            p = powMOD(powMOD, p, vals[idx]);
            ans.push_back(p);
        }

        return ans;
    }
};