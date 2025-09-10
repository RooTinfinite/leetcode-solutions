class Solution {
public:
    
    bool if_inline(vector<int> v1, vector<int> v2, vector<int> v3)
    {
        long long  x1 = v1[0]; long long  y1 = v1[1];
        long long  x2 = v2[0]; long long  y2 = v2[1];
        long long  x3 = v3[0]; long long  y3 = v3[1];
        long long  left = (x2-x1) * (y3-y1);
        long long  right = (y2-y1) * (x3-x1);
        if(left == right)
        {
            return true;
        }
        return false;
    }
    
    int minimumLines(vector<vector<int>>& nums) {
        sort(nums.begin(), nums.end());
        int count = 1;
        int m = nums.size();
        if(m == 1)
        {
            return 0;
        }
        if(m == 2) return 1;
        for (int i=1; i<m-1 ; i++)
        {
            if(! if_inline(nums[i-1], nums[i],nums[i+1]) ){
                count++;
            }
        }
        return count;
    }
};