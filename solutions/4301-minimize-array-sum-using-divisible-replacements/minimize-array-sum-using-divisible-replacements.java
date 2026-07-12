class Solution {

    public long minArraySum(int[] nums) {

        final int MAXV = 100000;

        boolean[] exists = new boolean[MAXV + 1];

        for(int x : nums) {
            exists[x] = true;
        }

        long ans = 0;

        for(int x : nums) {

            int best = x;

            // find smallest array element dividing x
            for(int d = 1; 1L * d * d <= x; d++) {

                if(x % d == 0) {

                    // divisor d
                    if(exists[d]) {
                        best = d;
                        break;
                    }

                    // paired divisor
                    int other = x / d;

                    if(exists[other]) {
                        best = Math.min(best, other);
                    }
                }
            }

            ans += best;
        }

        return ans;
    }
}