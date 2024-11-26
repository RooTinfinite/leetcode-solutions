class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
         vector<int>ans;
         int sum=0;
         for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0) sum+=nums[i];
         }

         for(int i=0;i<queries.size();i++){
            int idx=queries[i][1];
            int val=queries[i][0];
                if(abs(nums[idx])%2==0 && abs(val)%2==0){
                        sum+=val;
                        ans.push_back(sum);  
                        nums[idx]+=val;
                }
                else if(abs(nums[idx])%2==1 && abs(val)%2==1){
                    sum+=val+nums[idx];
                    nums[idx]+=val;
                    ans.push_back(sum);  
                }
                else if(abs(nums[idx])%2==1 && abs(val)%2==0){
                    nums[idx]+=val;
                    ans.push_back(sum);
                    cout<<sum;
                } 
                else{
                    ans.push_back(sum-nums[idx]);
                    sum-=nums[idx];
                    nums[idx] += val;
                }
          
         }
         return ans;
    }
};