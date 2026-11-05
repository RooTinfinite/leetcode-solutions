class Solution {
    public int peakValleyDifference(int[] nums) {
        int speak=0;
        int svalley=0;
        for(int i=1;i<nums.length-1;i++)
        {
            if(nums[i]>nums[i-1] && nums[i]>nums[i+1])
            speak=speak+nums[i];
            if(nums[i]<nums[i-1] && nums[i]<nums[i+1])
            svalley=svalley+nums[i];
        }
        return speak-svalley;
    }
}