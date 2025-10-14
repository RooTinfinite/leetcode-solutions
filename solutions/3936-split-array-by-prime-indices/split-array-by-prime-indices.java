class Solution {
    public long splitArray(int[] nums) {
        long sumA =0,sumB =0;
        
        for(int i =0;i<nums.length;i++){
            if(isPrime(i)){
                sumA+=nums[i]; // Prime index → Array A
            }else{
                sumB+=nums[i]; // Non-prime index → Array B
            }
        }
        return Math.abs(sumA-sumB);
    }
    private static boolean isPrime(int n){
        if (n<2) return false;
        if (n==2) return true;
        if (n%2 == 0) return false;
        for(int i =3; i*i<= n;i+= 2){
            if (n%i==0) return false;
        }
        return true;
    }
}