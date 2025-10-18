class Solution {
    public long maxTotal(int[] value, int[] limit) {
        Map<Integer, List<Integer>> buckets = new HashMap<>();
        int n = value.length;
        for (int i = 0; i < n; i++) {
            buckets.computeIfAbsent(limit[i], k -> new ArrayList<>()).add(value[i]);
        }
        long ans = 0;
        for (Map.Entry<Integer, List<Integer>> e : buckets.entrySet()) {
            int L = e.getKey();
            List<Integer> arr = e.getValue();
            arr.sort(Comparator.reverseOrder());
            int take = Math.min(L, arr.size());
            for (int i = 0; i < take; i++) ans += arr.get(i);
        }
        return ans;
    }
}