class Solution {
public:
    long long int sol = 0;

    void merge(vector<long long int>& st, vector<long long int>& temp,
               int l, int mid, int r, int goal, int k) {

        int p1 = l;
        int p2 = l;

        for (int j = mid + 1; j <= r; j++) {
            long long int x = st[j] - goal + k;

            while (p1 <= mid && st[p1] < x) {
                p1++;
            }

            sol += mid - p1 + 1;

            x = st[j] - goal - k;

            while (p2 <= mid && st[p2] <= x) {
                p2++;
            }

            sol += p2 - l;
        }

        int i = l;
        int j = mid + 1;
        int idx = l;

        while (i <= mid && j <= r) {
            if (st[i] <= st[j]) {
                temp[idx++] = st[i++];
            } else {
                temp[idx++] = st[j++];
            }
        }

        while (i <= mid) {
            temp[idx++] = st[i++];
        }

        while (j <= r) {
            temp[idx++] = st[j++];
        }

        for (int i = l; i <= r; i++) {
            st[i] = temp[i];
        }
    }
    void solve(vector<long long int>& st, vector<long long int>& temp, int l, int r, int goal, int k){
        if (l >= r) {
            return;
        }
        int mid = l + (r - l) / 2;
        solve(st, temp, l, mid, goal, k);
        solve(st, temp, mid + 1, r, goal, k);
        merge(st, temp, l, mid, r, goal, k);
    }
    long long distantSubarrays(vector<int>& nums, int goal, int k) {
        long long int n = nums.size();
        if (k == 0) {
            return 1ll * n * (n + 1) / 2;
        }
        vector<long long int> st;
        vector<long long int> temp(n + 1);
        long long int pre = 0;
        st.push_back(0);
        for (auto it : nums) {
            pre += it;
            st.push_back(pre);
        }
        solve(st, temp, 0, n, goal, k);
        return sol;
    }
};