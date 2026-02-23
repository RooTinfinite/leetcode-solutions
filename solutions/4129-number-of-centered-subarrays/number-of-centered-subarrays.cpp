const int N=2e5+1;
bitset<N> seen;
class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {
        const int n=nums.size();
        int cnt=n;// 1-element subarrays are centered
        auto [m, M]=minmax_element(nums.begin(), nums.end());
        const int bias=-*m, sz=*M-*m+1;
        for (int l=0; l<n-1; l++) {
            int sum=nums[l];
            seen.reset();
            seen[sum+bias]=1; 

            for (int r=l+1; r<n; r++) {
                const int x=nums[r];
                sum+=x;
                seen[x+bias]=1;
                if (0<=sum+bias && sum+bias<sz && seen[sum+bias])
                    cnt++;
            }
        }
        return cnt;
    }
};