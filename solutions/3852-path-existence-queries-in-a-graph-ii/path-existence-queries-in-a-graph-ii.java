class Solution {
    public int[] pathExistenceQueries(int n, int[] nums, int maxDiff, int[][] queries) {
        int[][] numsWithIdx = new int[n][2];
        for(int i = 0; i < n; i++) {
            numsWithIdx[i][0] = nums[i];
            numsWithIdx[i][1] = i;
        }
        Arrays.sort(numsWithIdx, (a, b) -> a[0]-b[0]);
        int[] map = new int[n]; //maps old array index (node index) to index in sorted array
        for(int i = 0; i < n; i++) map[numsWithIdx[i][1]] = i;
        
        int[][] jumps = new int[n][33 - Integer.numberOfLeadingZeros(n)];
        int right = 0;
        for(int i = 0; i < n; i++) {
            while(right + 1 < n && numsWithIdx[right+1][0]-numsWithIdx[i][0] <= maxDiff) right++;
            jumps[i][0] = right;
        }

        for(int j = 1; j < jumps[0].length; j++) {
            for(int i = 0; i < n; i++) {
                jumps[i][j] = jumps[jumps[i][j-1]][j-1]; //do two pow of 2 jumps to reach next pow of 2
            }
        }

        int m = queries.length;
        int[] res = new int[m];
        for(int i = 0; i < m; i++) {
            int u = Math.min(map[queries[i][0]], map[queries[i][1]]), v = Math.max(map[queries[i][0]], map[queries[i][1]]);
            res[i] = getQueryJumps(u, v, jumps); 
        }
        return res;
    }

    private int getQueryJumps(int u, int v, int[][] jumps) {
        if(u == v) return 0;
        if(jumps[u][0] >= v) return 1;
        if(jumps[u][jumps[u].length-1] < v) return -1;

        int lo = 0, hi = jumps[u].length;
        while(lo < hi) {
            int mid = (lo + hi) >>> 1;
            if(jumps[u][mid] < v) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        lo--;
        return (1 << lo) + getQueryJumps(jumps[u][lo], v, jumps);
    }
}