class Solution {
    public int maxBalancedSubarray(int[] nums) {
        Map<String, Integer> map=new HashMap<>();
        int isxor=0;
        int eveodd=0;
        int max=0;
        map.put("0!0",-1);
        for(int i=0;i<nums.length;i++){
            isxor^=nums[i];
            if((nums[i]&1)==1){
                eveodd++;
            }
            else{
                eveodd--;
            }
            String curr=isxor+"!"+eveodd;
            if(map.containsKey(curr)){
                max=Math.max(max,i-map.get(curr));
            }
            else{
                map.put(curr,i);
            }
        
        }
        return max;
    }
}