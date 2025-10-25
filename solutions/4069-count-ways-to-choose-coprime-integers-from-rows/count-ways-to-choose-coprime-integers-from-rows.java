class Solution {
    int gcd(int a, int b) {
        while (b != 0) {
            int temp = a % b;
            a = b;
            b = temp;
        }
        return a;
    }

    public int countCoprime(int[][] mat) {
        int MOD = 1_000_000_007;
        int m = mat.length;
        int n = mat[0].length;
        Map<Integer, Integer> dp = new HashMap<>();
        for (int i = 0; i < m; i++) {
            Map<Integer, Integer> dp2 = new HashMap<>();
            for (int num : mat[i]) {
                if (i == 0) {
                    dp2.put(num, (dp2.getOrDefault(num, 0) + 1) % MOD);
                } else {
                    for (int g : dp.keySet()) {
                        int newGcd = gcd(g, num);
                        dp2.put(newGcd, (dp2.getOrDefault(newGcd, 0) + dp.get(g)) % MOD);
                    }
                }
            }
            dp = dp2;
        }
        return dp.getOrDefault(1, 0);
    }
}