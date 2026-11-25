public class Solution {
    public int SmallestUniqueSubarray(int[] nums) {
        int n = nums.Length;

        int[] sa = new int[n];
        int[] rank = new int[n];
        int[] nextRank = new int[n];

        int maxRank = 0;
        for (int i = 0; i < n; ++i) {
            sa[i] = i;
            rank[i] = nums[i];
            maxRank = Math.Max(maxRank, rank[i]);
        }

        // Construct the sorted suffix array by doubling
        int[] temp = new int[n];
        int[] cnt = new int[Math.Max(n + 1, maxRank + 2)];

        void CountingSort(Func<int, int> getKey) {
            Array.Clear(cnt, 0, maxRank + 2);

            foreach (int i in sa) {
                ++cnt[getKey(i)];
            }

            for (int i = 1; i <= maxRank + 1; ++i) {
                cnt[i] += cnt[i - 1];
            }

            for (int p = n - 1; p >= 0; --p) {
                int i = sa[p];
                temp[--cnt[getKey(i)]] = i;
            }

            (sa, temp) = (temp, sa);
        }

        for (int k = 1; k < n; k <<= 1) {
            // Sort by the second key, then stably sort by the first key
            CountingSort(i => i + k < n ? rank[i + k] + 1 : 0);
            CountingSort(i => rank[i] + 1);

            nextRank[sa[0]] = 0;

            // Assign ranks to the newly sorted suffixes
            for (int i = 1; i < n; ++i) {
                int x = sa[i - 1], y = sa[i];
                int rx = x + k < n ? rank[x + k] : -1;
                int ry = y + k < n ? rank[y + k] : -1;

                nextRank[y] =
                    nextRank[x] + (rank[x] != rank[y] || rx != ry ? 1 : 0);
            }

            (rank, nextRank) = (nextRank, rank);
            maxRank = rank[sa[n - 1]];

            // All n suffixes have distinct ranks, so sorting is complete
            if (maxRank == n - 1) {
                break;
            }
        }

        // Construct LCP using Kasai's algorithm
        int[] pos = new int[n];
        int[] lcp = new int[n];
        for (int i = 0; i < n; ++i) {
            pos[sa[i]] = i;
        }

        int h = 0;
        for (int i = 0; i < n; ++i) {
            if (pos[i] == 0) {
                h = 0;
                continue;
            }

            int j = sa[pos[i] - 1];
            while (i + h < n && j + h < n && nums[i + h] == nums[j + h]) {
                ++h;
            }

            lcp[pos[i]] = h;

            if (h > 0) {
                --h;
            }
        }

        int answer = n;
        for (int i = 0; i < n; ++i) {
            int next = i + 1 < n ? lcp[i + 1] : 0;

            int need = Math.Max(lcp[i], next) + 1;
            if (sa[i] + need <= n) {
                answer = Math.Min(answer, need);
            }
        }

        return answer;
    }
}