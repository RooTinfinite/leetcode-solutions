class Solution {
public:
    int maximizeGreatness(vector<int>& nums) {
        int n=nums.size();

        sort(nums.begin(),nums.end());
        int greatness=0;
        int p=0;int q=1;  //two pointer

        while(q<n){
            if(nums[p]<nums[q]){   //case 1
                greatness++;
                p++;q++;
            }
            else{                  //case 2
                q++;
            }
        }

        return greatness;
        
    }
};