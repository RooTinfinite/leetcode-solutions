public class Solution {
    public bool CanSortArray(int[] nums) {
        // Store pairs of (min, max) values for each group of numbers with same bit count
        List<(int min, int max)> mm = new List<(int min, int max)>();
        
        // Initialize first group with first number
        mm.Add((nums[0], nums[0]));
        
        // Iterate through array starting from second element
        for (int i = 1; i < nums.Length; i++)
        {
            // Get bit count of current and previous numbers
            int cur = BitCount(nums[i]);
            int prev = BitCount(nums[i-1]);
            
            // If bit counts are different, start a new group
            if (cur != prev)
            {   
                mm.Add((nums[i], nums[i]));
            }
            
            // Update min and max values of current group
            var last = mm[mm.Count - 1];
            mm[mm.Count - 1] = (Math.Min(last.min, nums[i]), Math.Max(last.max, nums[i]));
        }
        
        // Check if groups can be sorted
        // For array to be sortable, max of previous group should be less than min of next group
        for (int i = 1; i < mm.Count; i++)
        {
            if (mm[i-1].max > mm[i].min)
                return false;
        }
        
        // If all groups can be sorted, return true
        return true;
    }
    
    private int BitCount(int n)
    {
        int count = 0;
        while (n != 0)
        {
            count += n & 1;
            n >>= 1;
        }
        return count;
    }
}