class Solution {
    public int[] maxKDistinct(int[] nums, int k) {
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length / 2; i++) {
            int temp = nums[i];
            nums[i] = nums[nums.length - 1 - i];
            nums[nums.length - 1 - i] = temp;
        }
        
        List<Integer> res = new ArrayList<>();
        res.add(nums[0]);
        k--;
        
        int i = 1;
        while(k > 0 && i < nums.length) {
            if(nums[i] != nums[i-1]) {
                res.add(nums[i]);
                k--;
            }
            i++;
        }
        
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}