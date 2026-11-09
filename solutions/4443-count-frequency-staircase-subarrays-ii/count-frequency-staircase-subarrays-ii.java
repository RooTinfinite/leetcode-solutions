class Solution {
    public int countStaircase(int[] nums) {
        int n = nums.length, maxK = 0;
        while ((long) (maxK + 1) * (maxK + 2) / 2 <= n) maxK++;

        int[] cnt = new int[100001], rank = new int[100001];
        int res = 0;

        for (int i = 0; i < n; i++) {
            int dist = 0, match = 0, end = i - 1;

            for (int j = i; j < n; j++) {
                end = j;
                int x = nums[j];

                if (cnt[x] == 0) {
                    if (++dist > maxK) break;
                    rank[x] = dist;
                    cnt[x] = 1;
                    if (dist == 1) match++;
                } else {
                    int r = rank[x];
                    if (cnt[x] >= r) break;
                    if (++cnt[x] == r) match++;
                }

                if (match == dist) res++;
            }

            for (int j = i; j <= end; j++) cnt[nums[j]] = 0;
        }

        return res;
    }
}