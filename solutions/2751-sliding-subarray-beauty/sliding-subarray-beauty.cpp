class Solution {
public:
    vector<int> getSubarrayBeauty(vector<int>& nums, int k, int x) {
        int n = nums.size();
        vector<int> freq(51, 0), ans;
        
        for(int i = 0, j = 0; i < n; i++) {
            // count freq of negative numbers in current sliding windows
            if(nums[i] < 0) freq[abs(nums[i])]++;
            if(i - j + 1 >= k) {
                int cnt = 0;
                // calculate xth smallest number in current sliding windows
                for(int L = 50; L >= 1; L--) {
                    cnt += freq[L];
                    if(cnt >= x) { ans.push_back(-L); break;}
                }
                // No xth smallest number present 
                if(cnt < x) ans.push_back(0);
                if(nums[j] < 0) freq[abs(nums[j])]--;
                j++;
            }
        }
        return ans;
        
    }
};