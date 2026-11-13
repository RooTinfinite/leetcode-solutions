class Solution {
public:
    int k = 7;
    int countSuffix(vector<int>& nums, vector<int>& target) {
        int n = nums.size();
        int res = 0;

        unordered_map<int, int> mpp1;
        unordered_map<int, int> mpp2;
        for(int num : nums) mpp1[num]++;
        for(int num : target) mpp2[num]++;

        if(mpp1 != mpp2) return 0;

        vector<bool> good(n, 0);
        for(int i = 0; i < n; i++){
            if(i == 0 || nums[i - 1] == target[i - 1]) good[i] = 1;
            else break;
        }
        int idx = n - 1;
        for(int i = n - 1; i >= 0; i--){
            if(i == n - 1 || target[i] >= target[i + 1]){
                idx = min(i, idx);
            }
            else break;
        }
        for(int i = idx; i < n; i++){
            if(good[i]) res++;
        }
        return res;
    }
};