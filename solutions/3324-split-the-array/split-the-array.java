class Solution {
    public boolean isPossibleToSplit(int[] nums) {
        HashMap<Integer,Integer> table = new HashMap<>();
        for(int i=0; i<nums.length; i++)
        {
            if(table.containsKey(nums[i]))
            {
                table.put(nums[i],table.get(nums[i])+1);
                    if(table.get(nums[i])>2)
                    {
                    return false;
                    }
            }

            else
            {
                table.put(nums[i],1);
            }
        }
        return true;
        
    }
}