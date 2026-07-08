class Solution {
    static final int n = 100004;
    static boolean[] sieve = new boolean[n];

    static {
        sieve[0] = sieve[1] = true;

        for (int i = 2; i <= 316; i++)
            if (!sieve[i])
                for (int j = i * i; j < n; j += i)
                    sieve[j] = true;
    }

    public int minOperations(int[] nums) {
        int res = 0;

        for (int i = 0; i < nums.length; i++) {
            int j = nums[i];

            if ((i & 1) == 1)
                while (!sieve[j++])
                    res++;
            else
                while (sieve[j++])
                    res++;
        }

        return res;
    }
}