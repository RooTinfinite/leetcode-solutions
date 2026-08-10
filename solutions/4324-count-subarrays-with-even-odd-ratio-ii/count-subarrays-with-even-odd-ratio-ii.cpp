class Solution {
    long long solve(vector<long long>& pref, int l, int r) {
        if(l >= r) return 0;
        int mid = l + (r - l) / 2;
        long long cnt = solve(pref, l, mid) + solve(pref, mid + 1, r);
        int j = mid + 1;
        for(int i = l; i <= mid; i++) {
            while(j <= r && pref[j] <= pref[i]) {
                j++;
            }
            cnt += (j - (mid + 1));
        }
        vector<long long> temp;
        int i = l;
        j = mid + 1;
        while(i <= mid && j <= r) {
            if(pref[i] <= pref[j]) {
                temp.push_back(pref[i]);
                i++;
            }
            else {
                temp.push_back(pref[j]);
                j++;
            }
        }
        while(i <= mid) {
            temp.push_back(pref[i]);
            i++;
        }
        while(j <= r) {
            temp.push_back(pref[j]);
            j++;
        }
        for(int k = 0; k < temp.size(); k++) {
            pref[l + k] = temp[k];
        }
        return cnt;
    }
    
public:
    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        long long ans = 0;
        int n = nums.size();
        vector<long long> pref(n + 1, 0);
        for(int i = 0; i < n; i++) {
            if(nums[i] % 2 == 0) pref[i + 1] = pref[i] + b;
            else pref[i + 1] = pref[i] - a;
        }
        ans = solve(pref, 0, n);
        return ans;
    }
};