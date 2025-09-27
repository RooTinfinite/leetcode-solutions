class Solution {
    public int[] resultArray(int[] nums) {
        int n = nums.length;
        List<Integer> arr1 = new ArrayList<>();
        List<Integer> arr2 = new ArrayList<>();
        int[] result = new int[n];
        for(int i=0;i<n;i++){
            if(i==0) arr1.add(nums[0]);
            else if(i==1) arr2.add(nums[1]);
            else{
                if(arr1.get(arr1.size()-1)>arr2.get(arr2.size()-1)){
                    arr1.add(nums[i]);
                }else{
                    arr2.add(nums[i]);
                }
            }
        }
        for(int i=0;i<arr1.size();i++){
            result[i]=arr1.get(i);
        }
        for(int i=0;i<arr2.size();i++){
            result[i+arr1.size()]=arr2.get(i);
        }
        return result;
    }
}