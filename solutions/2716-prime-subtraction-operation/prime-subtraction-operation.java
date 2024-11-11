class Solution {
    public boolean primeSubOperation(int[] nums) {
        int prevVal = 0;
        int idx = 0;
        int difference = 0;
        while(idx < nums.length-1){
            difference = nums[idx] - prevVal-1;
            if(difference < 0) return false;
            while(difference>0){
                if(isPrime(difference))break;
                difference--;
                
            }
            nums[idx]-=difference;
            prevVal=nums[idx++];
        }
        if(nums[idx] > prevVal)return true;
        return false;
    }
    public boolean isPrime(int x){
        if(x == 2) return true;
        if(x%2==0 || x==1)return false;
        int root = (int) Math.sqrt(x), start = 3;
        while(start <= root){
            if(x%start == 0) return false;
            start+=2;
        }
        return true;
    }
}