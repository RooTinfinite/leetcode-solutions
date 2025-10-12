class Solution {
    public boolean checkPrimeFrequency(int[] nums) {
        int n=nums.length;
        HashMap<Integer,Integer> map=new HashMap<>();
        for(int i:nums){
            map.put(i,map.getOrDefault(i,0)+1);
        }
        for(int i:map.values()){
            if(prime(i)){
                return true;
            }
        }
        return false;
    }
    boolean prime(int n){
       // if(n==1) return true;
        if(n<=1) return false;
        for(int i=2;i<=Math.sqrt(n);i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}