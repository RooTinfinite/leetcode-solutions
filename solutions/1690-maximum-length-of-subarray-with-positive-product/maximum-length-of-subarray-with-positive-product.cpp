class Solution {
public:
    int getMaxLen(vector<int>& nums) {
        int i=0;
        int j=0;
        int n=nums.size();
      long long  int prod=1;
        int ans=0;
        while(j<n){
           prod*=nums[j];
           if(prod>0){
               prod=1;
               ans=max(ans,j-i+1);
           }
           else if(prod==0){
               i=j+1;
               prod=1;
           }
           else 
           prod=-1;
           
           j++;
        

        }
       reverse(nums.begin(),nums.end());
         i=0;
         j=0;
         prod=1;
        int res=0;
        while(j<n){
           prod*=nums[j];
           if(prod>0){
               res=max(res,j-i+1);
               prod=1;
           }
           else if(prod==0){
               i=j+1;
               prod=1;
           }
           else
           prod=-1;
           
           j++;
        

        }
        cout<<res<<endl;
        ans=max(ans,res);
        
        return ans;

    }
};