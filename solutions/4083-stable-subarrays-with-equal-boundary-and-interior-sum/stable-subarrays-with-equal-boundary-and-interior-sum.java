class Solution {
    public long countStableSubarrays(int[] nums) {
        Map<Integer, Map<Long, Integer>> map = new HashMap<>();
        int n =  nums.length;
        long[] prefix = new long[n];
        long prevSum = 0;
        long count = 0;

        for(int i = 0; i < n; ++i) {
            prefix[i] = prevSum + nums[i];

            if(i >= 2) {
                if(!map.containsKey(nums[i - 2]))
                    map.put(nums[i - 2], new HashMap<>());

                Map<Long, Integer> innerMap = map.get(nums[i - 2]);
                innerMap.put(prefix[i - 2], innerMap.getOrDefault(prefix[i - 2], 0) + 1);
                map.put(nums[i - 2], innerMap);
            }

            if(map.containsKey(nums[i])) {
                Map<Long, Integer> innerMap = map.get(nums[i]);
                count += innerMap.getOrDefault(prefix[i] - 2 * nums[i], 0);
            }

            prevSum = prefix[i];
        }

        return count;
    }
}