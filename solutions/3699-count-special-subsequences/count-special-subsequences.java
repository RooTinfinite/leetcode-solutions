class Solution {
    public int bs(ArrayList<Integer> arr,int val){
        int low=0,high=arr.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr.get(mid)<=val) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
    public long numberOfSubsequences(int[] nums) {
        int n = nums.length;
        long ans=0;
        HashMap<Double,ArrayList<Integer>> hm = new HashMap<>();
        for(int i=0;i<n;i++){
            for(int j=i+2;j<n;j++){
                double val = nums[i]/(double)nums[j];
                if(hm.containsKey(val)){
                    hm.get(val).add(j);
                }else{
                    hm.put(val,new ArrayList<>(List.of(j)));
                }
            }
        }
        for(double d:hm.keySet()){
            Collections.sort(hm.get(d));
        }
        for(int i=4;i<n;i++){
            for(int j=i+2;j<n;j++){
                double val = nums[j]/(double)nums[i];
                if(hm.containsKey(val))ans+=bs(hm.get(val),i-2);
            }
        }
        return ans;
    }
}