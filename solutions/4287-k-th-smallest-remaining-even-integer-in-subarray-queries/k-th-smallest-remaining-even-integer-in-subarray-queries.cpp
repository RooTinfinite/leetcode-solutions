class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        vector<int> pref(n + 1, 0);

        for(int i = 0; i < n; ++i){
            pref[i + 1] = pref[i] + (nums[i] % 2 == 0);
        }
        
        vector<int> ans;

        for(auto& q : queries){
            int l = q[0], r = q[1], k = q[2];
            int low = l, high = r;
            int idx = -1;

            while(low <= high){
                int mid = low + (high - low) / 2;

                int fx = (nums[mid] / 2) - (pref[mid + 1] - pref[l]);

                if(fx >= k){
                    idx = mid;
                    high = mid - 1;
                }
                else low = mid + 1;
            }

            int removed = 0;

            if(idx == -1) removed = pref[r + 1] - pref[l];
            else removed = pref[idx] - pref[l];
            
            ans.push_back(2 * (k + removed));
        }

        return ans;
    }
};