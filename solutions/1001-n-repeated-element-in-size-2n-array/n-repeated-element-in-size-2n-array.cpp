class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        int p=nums.size();
        int n=p/2;
        int count;
        for(int i=0;i<p;i++)
        {
            count=0;
            for(int j=0;j<p;j++)
            {
                if(nums[i]==nums[j])
                   count++;
                
            }
            if(count==n)
               return nums[i];

        }
        return -1;
        
    }
};