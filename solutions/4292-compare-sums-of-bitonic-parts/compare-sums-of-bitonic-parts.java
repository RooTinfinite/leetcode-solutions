class Solution {
    public int compareBitonicSums(int[] nums) {
        int max = 0,maxelemidx = 0, N = nums.length;
        for(int index = 0 ; index < N ; index++){
            if(nums[index] > max){
                max = nums[index];
                maxelemidx = index;
            }
        }
        long ascsum = 0, descsum = 0;
        for(int index = 0 ; index <= maxelemidx ; index++) ascsum+=nums[index];
        for(int index = maxelemidx ; index < N ; index++) descsum+=nums[index];
        if(ascsum > descsum) return 0;
        else if(descsum > ascsum) return 1;
        else return -1;
    }
}