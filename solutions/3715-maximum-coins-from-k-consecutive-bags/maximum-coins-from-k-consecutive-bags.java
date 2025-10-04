class Solution {
    public long maximumCoins(int[][] coins, int k) {
        int n = n=coins.length;
        Arrays.sort(coins, (a, b)->a[0]-b[0]);
        long[] prefix = prefix(coins, n);
        //System.out.println(Arrays.toString(prefix));
        
        long maxCoins = 0;
        for(int i=0;i<n;i++){
            int start = coins[i][0], end = coins[i][1];
            int reqEnd = start+k-1, reqStart = end-k+1;

            // Cost For start to reqEnd(start+k-1);
            // Find highest index which l<=reqEnd
            int ub = upperBound(coins, n, reqEnd);
            if(ub != -1) {
                long totoalCoins1 = prefix[ub+1] - prefix[i];
                long extraCoins1 = coins[ub][2] * 1l * Math.max(coins[ub][1]-reqEnd, 0);
                maxCoins = Math.max(maxCoins, totoalCoins1 - extraCoins1);
            }
            

            // Cost For reqStart(end-k+1) to end;
            // Find smallest index which h>=reqStart
            int lb = lowerBound(coins, n, reqStart);
            if(lb < n) {
                long totoalCoins2 = prefix[i+1] - prefix[lb];
                long extraCoins2 = coins[lb][2] * 1l * Math.max(reqStart-coins[lb][0], 0);
                maxCoins = Math.max(maxCoins, totoalCoins2 - extraCoins2);
            }
        }
        return maxCoins;

    }

    private long[] prefix(int[][] coins, int n){
        long[] pre = new long[n+1];
        for(int i=0;i<n;i++){
            pre[i+1] = pre[i] + coins[i][2]*1l*(coins[i][1]-coins[i][0]+1);
        }
        return pre;
    }

    public int lowerBound(int[][] arr, int n, int x) {
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m][1] >= x) {
                h = m - 1;
            } else
                l = m + 1;
        }
        return l;
    }

    public int upperBound(int[][] arr, int n, int x) {
        int l = 0, h = n - 1;
        while (l <= h) {
            int m = l + (h - l) / 2;
            if (arr[m][0] <= x) {
                l = m + 1;
            } else
                h = m - 1;
        }
        return h;
    }
}