class Solution {
    public long[] countStableSubarrays(int[] nums, int[][] queries) {
        int n = nums.length;

        int[] nextBreak = new int[n];
        nextBreak[n - 1] = n;

        for(int i=n-2; i >= 0; i--){
            if(nums[i] <= nums[i + 1])
                nextBreak[i] = nextBreak[i + 1];
            else
                nextBreak[i] = i+1;
        }

        long[] ways = new long[n];
        for(int i=0; i <n ; i++){
            long len = nextBreak[i] - i;
            ways[i] = len * (len + 1) / 2;
        }

        long[] pref = new long[n + 1];
        for(int i = n-1; i >= 0; i--){
            pref[i] = pref[i + 1] + ways[i];
        }

        java.util.ArrayList<Integer> starts = new java.util.ArrayList<>();
        java.util.ArrayList<Integer> ends = new java.util.ArrayList<>();

        int p=0;
        while(p < n){
            int s = p;
            int q = p;
            while(q + 1 < n && nums[q] <= nums[q+1]) q++;
            starts.add(s);
            ends.add(q);
            p = q + 1;
        }

        int B = starts.size();

        int[] blockId = new int[n];
        for(int b = 0; b < B; b++){
            int s = starts.get(b), e = ends.get(b);
            for(int idx = s; idx <= e; idx++) blockId[idx] = b;
        }

        long blockWays[] = new long[B];
        for(int b=0; b < B; b++){
            long len = (long)ends.get(b) - starts.get(b) + 1L;
            blockWays[b] = len * (len + 1L) / 2L;
        }

        long[] prefBlock = new long[B + 1];
        for(int b = B - 1; b >= 0; b--) prefBlock[b] = prefBlock[b + 1] + blockWays[b];

        long[] ans = new long[queries.length];

        for(int qi=0; qi < queries.length; qi++){
            int l = queries[qi][0];
            int r = queries[qi][1];
            
            int bl = blockId[l];
            int br = blockId[r];

            if(bl == br){
                long len = (long)r - l + 1L;
                ans[qi] = len * (len + 1L) / 2L;
                continue;
            }

            int endBl = ends.get(bl);
            long len1 = (long)endBl - l + 1L;
            long res = len1 * (len1 + 1L) / 2L;

            int startBr = starts.get(br);
            long len2 = (long)r - startBr + 1L;
            res += len2 * (len2 + 1L) / 2L;

            if(bl + 1 <= br - 1){
                res += prefBlock[bl + 1] - prefBlock[br];
            }

            ans[qi] = res;
        }
        return ans;
    }
}