class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
          int n = nums.size();
          int maxi = INT_MIN;
           int mini = INT_MAX;
           int a=0,b=0;

            for(int i=0;i<n;i++)
            {
                 if(nums[i]>maxi)
                 {
                     maxi = nums[i];
                     a = i;
                 }

                 if(nums[i]<mini)
                 {
                   mini = nums[i];
                    b = i;
                 } 
            }
            if(a>b)
            {
                 swap(a,b);
            }

            int op1 =a+1+(n-b);
            int op2 = n-a;
            int op3 = b+1;


      return min({op1,op2,op3});
    }
};