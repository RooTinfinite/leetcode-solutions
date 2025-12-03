public class Solution {
    public int CountTrapezoids(int[][] points) {
        int n = points.Length;
        double inf = 1e9 + 7;
        Dictionary<double, List<double>> slopeToIntercept =
            new Dictionary<double, List<double>>();
        Dictionary<double, List<double>> midToSlope =
            new Dictionary<double, List<double>>();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int x1 = points[i][0], y1 = points[i][1];
            for (int j = i + 1; j < n; j++) {
                int x2 = points[j][0], y2 = points[j][1];
                int dx = x1 - x2;
                int dy = y1 - y2;

                double k, b;
                if (x2 == x1) {
                    k = inf;
                    b = x1;
                } else {
                    k = (double)(y2 - y1) / (x2 - x1);
                    b = (double)(y1 * dx - x1 * dy) / dx;
                }

                double mid = (x1 + x2) * 10000.0 + (y1 + y2);
                if (!slopeToIntercept.ContainsKey(k)) {
                    slopeToIntercept[k] = new List<double>();
                }
                if (!midToSlope.ContainsKey(mid)) {
                    midToSlope[mid] = new List<double>();
                }
                slopeToIntercept[k].Add(b);
                midToSlope[mid].Add(k);
            }
        }

        foreach (var sti in slopeToIntercept.Values) {
            if (sti.Count == 1) {
                continue;
            }
            Dictionary<double, int> cnt = new Dictionary<double, int>();
            foreach (double bVal in sti) {
                cnt[bVal] = cnt.GetValueOrDefault(bVal, 0) + 1;
            }
            int totalSum = 0;
            foreach (int count in cnt.Values) {
                ans += totalSum * count;
                totalSum += count;
            }
        }

        foreach (var mts in midToSlope.Values) {
            if (mts.Count == 1) {
                continue;
            }
            Dictionary<double, int> cnt = new Dictionary<double, int>();
            foreach (double kVal in mts) {
                cnt[kVal] = cnt.GetValueOrDefault(kVal, 0) + 1;
            }

            int totalSum = 0;
            foreach (int count in cnt.Values) {
                ans -= totalSum * count;
                totalSum += count;
            }
        }

        return ans;
    }
}