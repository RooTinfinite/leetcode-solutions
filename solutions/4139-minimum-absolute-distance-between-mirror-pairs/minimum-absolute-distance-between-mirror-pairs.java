class Solution {
    public int minMirrorPairDistance(int[] nums) {
        Map<Integer,Integer> map=new HashMap<>();
        int n=nums.length;
        for(int i=0;i<n;i++){
            map.put(nums[i],i);
        }
        int min=Integer.MAX_VALUE;
        for(int i=0;i<n;i++){
            int r=reverse(nums[i]);
            if(map.containsKey(r) && i<map.get(r)){
                min=Math.min(min,Math.abs(i-map.get(r)));
            }
        }
        return min==Integer.MAX_VALUE?-1:min;
    }
    public static int reverse(int n){
        StringBuilder sb=new StringBuilder(Integer.toString(n));
        return Integer.parseInt(sb.reverse().toString());
    }
}