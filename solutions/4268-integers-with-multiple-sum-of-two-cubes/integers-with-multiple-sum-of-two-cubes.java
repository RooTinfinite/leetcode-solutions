class Solution {
    public List<Integer> findGoodIntegers(int n) {
        Map<Integer, Integer> mp = new HashMap<>();
        List<Integer> ans = new ArrayList<>();

        int limit = (int)Math.cbrt(n);

        for (long i = 1; i <= limit; i++) {
            long i3 = i * i * i;

            for (long j = i; j <= limit; j++) {
                long sum = i3 + j * j * j;

                if (sum > n) break;

                mp.put((int)sum, mp.getOrDefault((int)sum, 0) + 1);
            }
        }

        for (Map.Entry<Integer, Integer> it : mp.entrySet()) {
            if (it.getValue() >= 2) {
                ans.add(it.getKey());
            }
        }

        Collections.sort(ans);
        return ans;
    }
}