class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();

        vector<int>ans(n,-1);

        for(int i=0;i<nums.size();i++){
            int num=nums[i];

            if(num<=2)continue;

            vector<int>bit(32,0);//used for calculating bits of num

            for(int j=0;j<31;j++){

                int digit=(num>>j)&1;

                bit[j]=digit;

            }

            int tempans=num-1; //always num-1 answer is possible as num is prime number so it is always odd if we neglect one then tempans is equal to num-1

            int sum=num;//total sum



            //below loop is traversing and neglect the bit which has bit[j]=1; and calculate the currsum that is check  . if check is possible ans then we update tempans 
            for(int j=0;j<31;j++){

                if(bit[j]){

                    int check=sum-(1<<j);

                    if((check|(check+1))==num){tempans=min(tempans,check);}
                }

            }
            
            ans[i]=tempans; //minimum of all            

        }

        return ans;
    }
};