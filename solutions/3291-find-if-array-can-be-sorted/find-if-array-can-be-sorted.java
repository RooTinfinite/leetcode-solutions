class Solution {
    public boolean canSortArray(int[] nums) {
        // Initialize list to store groups of numbers with same bit count
        List<List<Integer>> groups = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        Integer currBits = null;
        
        // Iterate through each number in input array
        for (int num : nums) {
            // If this is start of first group, set initial bit count
            if (currBits == null) {
                currBits = Integer.bitCount(num);
            }
            
            // If current number has same bit count as current group
            if (Integer.bitCount(num) == currBits) {
                curr.add(num);
            } else {
                // Different bit count found
                currBits = Integer.bitCount(num);
                groups.add(new ArrayList<>(curr));
                curr.clear();
                curr.add(num);
            }
        }
        
        // Add final group if exists
        if (!curr.isEmpty()) {
            groups.add(new ArrayList<>(curr));
        }
        
        // Build output array by sorting each group internally
        List<Integer> out = new ArrayList<>();
        for (List<Integer> g : groups) {
            Collections.sort(g);
            out.addAll(g);
        }
        
        // Create sorted version of original array for comparison
        int[] sortedNums = nums.clone();
        Arrays.sort(sortedNums);
        
        // Compare sorted output with sorted input
        int i = 0;
        for (int num : out) {
            if (num != sortedNums[i++]) {
                return false;
            }
        }
        
        return true;
    }
}