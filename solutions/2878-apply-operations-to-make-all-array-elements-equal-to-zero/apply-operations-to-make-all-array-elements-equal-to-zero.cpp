class Solution {
public:
    bool checkArray(vector<int>& nums, int k) 
    {
        int n = nums.size();
        int sum = 0;
        vector<pair<int, int>> v;
        int j = 0;
        for(int i=0; i<n; i++) 
        {
            while(j<v.size() && i-v[j].first>=k) 
            {
                sum -= v[j].second;
                j++;
            }
            if(nums[i]<sum) 
            {
                return false;
            }
            nums[i] -= sum;
            if(nums[i]>0) 
            {
                v.push_back({i, nums[i]});
                int temp = nums[i];
                nums[i] = 0;
                sum += temp;
            }
        }
        while (j<v.size() && n-v[j].first>=k) 
        {
            j++;
        }
        int mx=-1e9;
        for(int x: nums) mx=max(mx, x);
        return mx==0 && j==v.size();
    }
};