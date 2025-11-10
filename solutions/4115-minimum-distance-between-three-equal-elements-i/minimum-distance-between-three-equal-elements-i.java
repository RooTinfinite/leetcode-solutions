class Solution {
    public int minimumDistance(int[] nums) {
        int n = nums.length;
        
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int i = 0; i < n; ++i)
            map.computeIfAbsent(nums[i], k -> new ArrayList<>()).add(i);

        int ans = Integer.MAX_VALUE;
        for (Map.Entry<Integer, List<Integer>> em : map.entrySet()) {
            int t = 0;
            List<Integer> ref = em.getValue();
            
            if (ref.size() < 3)
                continue;
            
            for (int j = 0; j < ref.size() - 2; ++j) {
                t = Math.abs(ref.get(j) - ref.get(j + 1)) + Math.abs(ref.get(j + 1) - ref.get(j + 2))
                        + Math.abs(ref.get(j + 2) - ref.get(j));
                ans = Math.min(ans, t);
            }
        }
        
        return ans == Integer.MAX_VALUE ? -1 : ans;
    }
}