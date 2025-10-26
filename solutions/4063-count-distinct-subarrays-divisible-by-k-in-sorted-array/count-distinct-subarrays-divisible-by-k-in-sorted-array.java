class Solution {
    public long numGoodSubarrays(int[] nums, int k) {
        Map<Integer,Long> map=new HashMap<>();
        map.put(0,1L);
        long ans=0,sum=0;
        int i=0,n=nums.length;
        while(i<n){
            Map<Integer,Long> temp=new HashMap<>();
            int val=nums[i];
            while(i<n && nums[i]==val){
                sum+=nums[i];
                int rem=(int)(sum%k);
                temp.put(rem,temp.getOrDefault(rem,0L)+1);
                ans+=map.getOrDefault(rem,0L);
                i++;
            }
            for(int key:temp.keySet()){
                map.put(key,map.getOrDefault(key,0L)+temp.get(key));
            }
        }
        return ans;
    }
}