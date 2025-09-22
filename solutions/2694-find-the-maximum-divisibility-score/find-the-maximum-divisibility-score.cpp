class Solution {
public:
    int maxDivScore(vector<int>& nums, vector<int>& divisors) {

        int n = divisors.size();
        int maxcount=INT_MIN;
        int minelement = INT_MAX;
        
        for(int i=0;i<n;i++){
            
            int count=0;
            for(int j=0;j<nums.size();j++){

                if(nums[j]%divisors[i]==0){
                    count++;

                }
            }
           
   // find max count, if count are equal check for the smallest divisor availbe         
            if(count>maxcount || (count==maxcount && divisors[i]<minelement) ){
                maxcount = count;
                minelement=divisors[i];


            }



        }
        return minelement;
        
    }
};