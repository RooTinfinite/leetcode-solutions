class Solution {
public:
Solution()
    {
        ios_base::sync_with_stdio(false); 
        cin.tie(NULL); 
        cout.tie(NULL);
        
    }
    int maxOperations(vector<int>& nums, int k) {

        sort(nums.begin(),nums.end());
        int start=0;
        int end=nums.size()-1;
        int count =0;

        while(start<end){

            if(nums[start]+nums[end]==k){
                start++;
                end--;
                count++;
            }
            else if(nums[start]+nums[end]<k){
                start++;
            }
            else if(nums[start]+nums[end]>k){
                end--;
            }

        }
        return count;
        
     }
};