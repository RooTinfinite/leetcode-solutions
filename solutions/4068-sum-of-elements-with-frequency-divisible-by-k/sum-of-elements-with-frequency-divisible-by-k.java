class Solution {
    public int sumDivisibleByK(int[] nums, int k) {
        Set<Integer> s = new HashSet<>();
        for (int n : nums) s.add(n);
        int count = 0;

        for (int i : s) {
            int cnt = 0;
            for (int n : nums) {
                if (n == i) cnt++;
            }
            if (cnt % k == 0) count += i * cnt;
        }

        return count;
    }
}