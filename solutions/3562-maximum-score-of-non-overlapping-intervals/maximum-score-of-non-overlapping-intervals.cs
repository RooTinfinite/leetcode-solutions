public class Solution {
    public int[] MaximumWeight(IList<IList<int>> intervals) {
        int n = intervals.Count;
        int[][] arr = new int [n][];
        for (int i = 0; i < n; i++) {
            arr[i] = new int[] { intervals[i][0], intervals[i][1],
                                 intervals[i][2], i };
        }
        // Sort by right endpoint.
        Array.Sort(arr, (a, b) => a[1].CompareTo(b[1]));

        long[][] dp = new long [n + 1][];
        List<int>[][] indices = new List<int> [n + 1][];
        for (int i = 0; i <= n; i++) {
            dp[i] = new long[5];
            indices[i] = new List<int>[5];
            for (int j = 0; j < 5; j++) {
                indices[i][j] = new List<int>();
            }
        }

        for (int i = 0; i < n; i++) {
            int l = arr[i][0], weight = arr[i][2], idx = arr[i][3];
            // Use binary search to find intervals whose right endpoints are
            // smaller than l.
            int k = BinarySearch(arr, i, l);

            for (int j = 1; j < 5; j++) {
                long s1 = dp[i][j];
                long s2 = dp[k][j - 1] + weight;
                if (s1 > s2) {
                    dp[i + 1][j] = dp[i][j];
                    indices[i + 1][j] = new List<int>(indices[i][j]);
                    continue;
                }

                List<int> newIndex = new List<int>(indices[k][j - 1]);
                newIndex.Add(idx);
                newIndex.Sort();
                if (s1 == s2 && CompareLists(indices[i][j], newIndex) < 0) {
                    newIndex = new List<int>(indices[i][j]);
                }
                dp[i + 1][j] = s2;
                indices[i + 1][j] = newIndex;
            }
        }

        return indices[n][4].ToArray();
    }

    private int BinarySearch(int[][] arr, int end, int target) {
        int left = 0, right = end;
        while (left < right) {
            int mid = (left + right) / 2;
            if (arr[mid][1] < target) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }

    private int CompareLists(List<int> a, List<int> b) {
        int minLen = Math.Min(a.Count, b.Count);
        for (int i = 0; i < minLen; i++) {
            if (a[i] != b[i]) {
                return a[i].CompareTo(b[i]);
            }
        }
        return a.Count.CompareTo(b.Count);
    }
}