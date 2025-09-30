class Solution {
    public int minChanges(int[] nums, int k) {
        HashMap<Integer, Integer> hm = new HashMap<>();
        int[] differences = new int[nums.length / 2];
        int index = 0;

        // Calculating frequency differences
        for (int i = 0; i < nums.length / 2; i++) {
            int difference = Math.abs(nums[i] - nums[nums.length - i - 1]);
            hm.put(difference, hm.getOrDefault(difference, 0) + 1);
        }

        // Calculating the threshold values
        for (int i = 0; i < differences.length; i++) {
            int a = nums[i];
            int b = nums[nums.length - 1 - i];
            differences[i] = Math.max(Math.max(a, b), k - Math.min(a, b));
        }

        // Sorting the differences array
        Arrays.sort(differences);

        int ans = Integer.MAX_VALUE;

        // Iterating over the HashMap entries
        for (Map.Entry<Integer, Integer> entry : hm.entrySet()) {
            int key = entry.getKey();
            int value = differences.length - entry.getValue();

            int idx = lowerBound(differences, key);
            
            value += idx;
            ans = Math.min(ans, value);
        }
        return ans;
    }
    public int lowerBound(int[] sortedArray, int target) {
        int low = 0;
        int high = sortedArray.length;
        
        while (low < high) {
            int mid = low + (high - low) / 2;
            
            if (sortedArray[mid] < target) {
                low = mid + 1;
            } else {
                high = mid;
            }
        }
        
        return low;
    }
}