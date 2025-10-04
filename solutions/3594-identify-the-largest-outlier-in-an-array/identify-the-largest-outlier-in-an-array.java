class Solution {
    public int getLargestOutlier(int[] nums) {
        Map<Integer, Integer> ctr = new HashMap<>();
        int sm = 0;

        for (int num : nums) {
            ctr.put(num, ctr.getOrDefault(num, 0) + 1);
            sm += num;
        }

        List<Integer> cands = new ArrayList<>(ctr.keySet());
        cands.sort(Collections.reverseOrder());

        for (int n : cands) {
            int d = (sm - n) / 2;
            int m = (sm - n) % 2;
            if (m == 0 && ctr.containsKey(d) && (d != n || ctr.get(d) > 1)) {
                return n;
            }
        }

        return -1; 
    }
}