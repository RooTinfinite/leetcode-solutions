class Solution {
    public int countStableSubsequences(int[] nums) {
        int MOD = 1_000_000_007;

        long eoo = 0; // ending with 1 odd
        long eto = 0; // ending with 2 odds
        long eoe = 0; // ending with 1 even
        long ete = 0; // ending with 2 evens

        for (int num : nums) {
            if (num % 2 != 0) { // odd
                long nooc = (eoe + ete + 1) % MOD; // start new odd subsequences
                long ntoc = eoo;                     // extend sequences ending with 1 odd
                eoo = (eoo + nooc) % MOD;
                eto = (eto + ntoc) % MOD;
            } else { // even
                long noec = (eoo + eto + 1) % MOD; // start new even subsequences
                long ntec = eoe;                     // extend sequences ending with 1 even
                eoe = (eoe + noec) % MOD;
                ete = (ete + ntec) % MOD;
            }
        }

        long ans = (eoo + eto + eoe + ete) % MOD;
        return (int) ans;
    }
}