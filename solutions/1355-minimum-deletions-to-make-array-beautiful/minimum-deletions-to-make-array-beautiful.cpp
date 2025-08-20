class Solution {
public:
    int minDeletion(vector<int>& nums) {
        if(nums.size()==1 ){
          return 1;
        }
        int i=0;
        int count =0;
        
        while(i<nums.size()-1){
           if(nums[i]==nums[i+1]){
              count++;
               i++;
           }
           else{
               i+=2;
           }    
        }
        if(i == nums.size()-1){
          count++;
        }
    return count;   
    }
};