class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<bool>> dp(n+1,vector<bool>(k+1));

        //sorting array
        sort(nums.begin(),nums.end());

        //classic subset-sum started
        for(int i=0;i<=n;i++){
            for(int j=0;j<=k;j++)
            {
                if(i==0) dp[i][j]=false;
                if(j==0) dp[i][j]=true;
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k;j++)
            {
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        //classic subset-sum finished 

        vector<bool> ans;
        for(int x=1;x<=n;x++)
        {
            auto it = upper_bound(nums.begin(),nums.end(),x);
            //it will give us the first index which is just greater than x

            if(it==nums.end())  //if no element in nums is greater than x
            {
                ans.push_back(dp[n][k]); //since no capping will be done -> original array answer
            }else{

                int ind = it-nums.begin();
                //this is the index which is just greater than x.

                int sz = n-ind;
                //number of elements in array greater than x -> all of them will become x 

                bool flg = false;
                for(int j=0;j<=k;j++)
                {
                    if(dp[ind][j]) //we check if using first 'ind' elements what all sum values are possible
                    {
                        //for each sum value possible, we check if sumval + p*x == k. means taking any multiple of x and adding to sumval can we get desired output of k

                        int reman = k-j;
                        if(reman%x==0){
                            int multiple = reman/x; 
                            if(multiple<=sz){ //if number of x we need is lesser than how much we have in store then only
                                flg = true;
                                break;
                            }
                        }
                    }
                    if(flg) break;
                }
                ans.push_back(flg);
            }
        }

        return ans;


        
    }
};