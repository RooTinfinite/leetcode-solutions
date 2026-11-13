class Solution {
    public long countNonDecreasingSubarrays(int[] nums, int K) {
        int n = nums.length;


        long[] prefixSum = new long[n+1];
        for(int i = 0; i < n; i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }


        int[] nextG = buildNextGreater(nums);


        int LOG = 1;
        while((1<<LOG) <= n) LOG++;
        int[][] jump = new int[n][LOG];
        long[][] costJump = new long[n][LOG];


        for(int i = 0; i < n; i++) {
            jump[i][0] = nextG[i];
            costJump[i][0] = (long)nums[i] * (Math.min(nextG[i], n) - i);
        }


        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i < n; i++) {
                int mid = jump[i][k-1];
                if(mid >= n) {
                    jump[i][k] = mid;
                    costJump[i][k] = costJump[i][k-1];
                } else {
                    jump[i][k] = jump[mid][k-1];
                    costJump[i][k] = costJump[i][k-1] + costJump[mid][k-1];
                }
            }
        }


        long ans = 0;


        for(int L = 0; L < n; L++) {
            int low = L, high = n - 1, validR = L - 1; 
            while(low <= high) {
                int mid = (low + high) >>> 1;
                long cst = costLR(L, mid, nums, prefixSum, jump, costJump);
                if(cst <= K) {
                    validR = mid;
                    low = mid + 1;
                } else {
                    high = mid - 1;
                }
            }
            if(validR >= L) {
                ans += (validR - L + 1);
            }
        }


        return ans;
    }


    public long costLR(int L, int R, int[] nums, long[] prefixSum, int[][] jump, long[][] costJump){
        if (L > R) return 0;
        long sumLR = prefixSum[R+1] - prefixSum[L];
        long maxSum = getSumOfMaxima(L, R, nums, jump, costJump);
        return maxSum - sumLR;
    }


    public long getSumOfMaxima(int start, int R, int[] nums, int[][] jump, long[][] costJump) {
        long res = 0;
        int x = start;
        while(x <= R) {
            int cur = x;
            for(int k = jump[x].length - 1; k >= 0; k--) {
                int nxt = jump[cur][k];
                if(nxt <= R) {
                    res += costJump[cur][k];
                    cur = nxt;
                }
            }
            if(cur <= R) {
                long costFull = costJump[cur][0];
                int g = jump[cur][0];
                int segmentLen = Math.min(g, R+1) - cur; 
                long costPartial = (long)nums[cur] * segmentLen;
                res += costPartial;
                cur = g;
            }
            x = cur;
        }
        return res;
    }


    public int[] buildNextGreater(int[] nums) {
        int n = nums.length;
        int[] ng = new int[n];
        Arrays.fill(ng, n);
        Deque<Integer> st = new ArrayDeque<>();
        for(int i = n - 1; i >= 0; i--) {
            while(!st.isEmpty() && nums[st.peek()] <= nums[i]) {
                st.pop();
            }
            if(!st.isEmpty()) {
                ng[i] = st.peek();
            }
            st.push(i);
        }
        return ng;
    }
}