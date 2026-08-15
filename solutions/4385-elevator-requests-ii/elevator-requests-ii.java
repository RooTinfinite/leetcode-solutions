
class Solution {
    public long elevatorRequests(int n, int start, int[] requests) {
        int[] request = requests.clone();
        int m = 0;

        for (int x : request) {
            if (x != start) {
                m++;
            }
        }

        if (m == 0) {
            return 0L;
        }

        int[] a = new int[m];
        int idx = 0;

        for (int x : request) {
            if (x != start) {
                a[idx++] = x;
            }
        }

        Arrays.sort(a);

        int size = m * m;
        long INF = Long.MAX_VALUE / 4;

        long[] dpL = new long[size];
        long[] dpR = new long[size];

        Arrays.fill(dpL, INF);
        Arrays.fill(dpR, INF);

        for (int i = 0; i < m; i++) {
            long cost = Math.abs((long) start - a[i]) * m;
            int pos = i * m + i;

            dpL[pos] = cost;
            dpR[pos] = cost;
        }

        for (int len = 1; len <= m; len++) {
            int remaining = m - len;

            for (int l = 0; l + len - 1 < m; l++) {
                int r = l + len - 1;
                int pos = l * m + r;

                long leftCost = dpL[pos];
                long rightCost = dpR[pos];

                if (r + 1 < m) {
                    int nr = r + 1;
                    int nextPos = l * m + nr;

                    if (leftCost != INF) {
                        long distance = Math.abs((long) a[l] - a[nr]);

                        dpR[nextPos] = Math.min(dpR[nextPos], leftCost + distance * remaining);
                    }

                    if (rightCost != INF) {
                        long distance = Math.abs((long) a[r] - a[nr]);

                        dpR[nextPos] = Math.min(
                                dpR[nextPos],
                                rightCost + distance * remaining);
                    }
                }

                if (l - 1 >= 0) {

                    int nl = l - 1;
                    int nextPos = nl * m + r;

                    if (leftCost != INF) {
                        long distance = Math.abs((long) a[l] - a[nl]);

                        dpL[nextPos] = Math.min(
                                dpL[nextPos],
                                leftCost + distance * remaining);
                    }

                    if (rightCost != INF) {
                        long distance = Math.abs((long) a[r] - a[nl]);

                        dpL[nextPos] = Math.min(
                                dpL[nextPos],
                                rightCost + distance * remaining);
                    }
                }
            }
        }

        int finalPos = m - 1;

        return Math.min(
                dpL[finalPos],
                dpR[finalPos]);
    }
}