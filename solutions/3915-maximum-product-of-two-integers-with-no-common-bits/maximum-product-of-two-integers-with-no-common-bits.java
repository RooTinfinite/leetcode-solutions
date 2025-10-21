class Solution {
    public long maxProduct(int[] nums) {
        int max=0;
        for(int val:nums)max=Math.max(max,val);
        int totalBit=(int)(Math.log(max)/Math.log(2) + 1);
        int maxMask=(1<<totalBit)-1;

        /*dp[val] tells if we represent val in binary number then all set bit everytime goes to unset
        then from all subset take max of them and store in dp[val]
        eg: comp=0101 take all combination of set bit to unset means place 1->0 or no change(means itself)
        [0100,0001,0000,itself 0101]*/
        int[] dp=new int[maxMask+1];
        for(int val:nums)dp[val]=val;
        
        for(int i=0; i<totalBit; i++){
            for(int val=1; val<=maxMask; val++){
                /*every time every set bit goes to unset and we take maximum from all of them*/
                if((val & (1<<i) )!=0){//only for set bit we need to unset
                    int offBitNumber=(val ^ (1<<i));//set bit -> unset
                    dp[val]=Math.max(dp[val],dp[offBitNumber]);
                }
            }
        }
        long ans=0;
        for(int val:nums){
            /*take complement of val and look for dp[comp] which tells all subset including itself 
            gives max where in every subset every alter set bit goes to unset
            eg: val=1010 comp=0101 take all combination of set bit in comp means place 1->0
            [0100,0001,0000,itself 0101]*/ 
            int comp=(maxMask ^ val);
            ans=Math.max(ans,(long)val*dp[comp]);
        }
        return ans;
    }
} 
//Time=> O(N∗Log(Max(Nums)))
//Space=> O(Max(Nums))