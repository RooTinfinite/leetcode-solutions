class Solution {
    private boolean isPrime(int n){ //Function to check whether a number is prime or not
        if(n<2)
            return false;
        if(n==2)
            return true;
        for(int i=2; i*i <=n; i++){
             if(n%i==0)
                 return false;
        }
        return true;
    }
    public int maximumPrimeDifference(int[] nums) {
        int l=0;
        int r=nums.length-1;
        while(l<=r){
            if(!isPrime(nums[l]))
                l++;
            if(!isPrime(nums[r]))
                r--;
            if(isPrime(nums[l]) && isPrime(nums[r]))
                return r-l;
        }
        return 0;
    }
}