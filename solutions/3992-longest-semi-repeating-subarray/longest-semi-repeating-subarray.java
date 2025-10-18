

import static java.util.Collections.max;

class Solution {
    public int longestSubarray(int[] nums, int k) {
        Map<Integer,Integer> count = new HashMap<>();
        int left =0, repeatingCount =0, maxLen =0;

        for(int right =0;right<nums.length;right++){
            int num = nums[right];
            count.put(num, count.getOrDefault(num, 0)+1);
            if(count.get(num)==2)repeatingCount++;

            while(repeatingCount>k){
                int leftNum = nums[left];
                count.put(leftNum, count.get(leftNum)-1);
                if(count.get(leftNum)==1)repeatingCount--;
                left++;
            }
            maxLen = Math.max(maxLen, right-left+1);
        }
         return maxLen;
    }
}