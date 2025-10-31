class Solution {

    public int[] getSneakyNumbers(int[] nums) {
        List<Integer> res = new ArrayList<>();
        Map<Integer, Integer> count = new HashMap<>();
        for (int x : nums) {
            int c = count.getOrDefault(x, 0) + 1;
            count.put(x, c);
            if (c == 2) {
                res.add(x);
            }
        }
        return res.stream().mapToInt(Integer::intValue).toArray();
    }
}