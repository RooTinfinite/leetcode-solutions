public class Solution {
    private static readonly int[][] DIRS =
        new int[][] { new int[] { 0, 1 }, new int[] { 0, -1 },
                      new int[] { 1, 0 }, new int[] { -1, 0 } };

    public bool FindSafeWalk(IList<IList<int>> grid, int health) {
        int m = grid.Count, n = grid[0].Count;
        int[][] dis = new int [m][];
        for (int i = 0; i < m; i++) {
            dis[i] = new int[n];
            Array.Fill(dis[i], int.MaxValue);
        }

        var q = new LinkedList<int[]>();
        q.AddFirst(new int[] { 0, 0 });
        dis[0][0] = grid[0][0];

        while (q.Count > 0) {
            int[] cur = q.First.Value;
            q.RemoveFirst();
            int cx = cur[0], cy = cur[1];
            // the first time it leaves the queue, the shortest distance is
            // guaranteed
            if (cx == m - 1 && cy == n - 1) {
                return true;
            }

            foreach (var dir in DIRS) {
                int nx = cx + dir[0], ny = cy + dir[1];
                if (nx < 0 || ny < 0 || nx >= m || ny >= n) {
                    continue;
                }
                int cost = dis[cx][cy] + grid[nx][ny];
                // pruning: the new distance does not meet health requirements
                if (cost >= health) {
                    continue;
                }
                if (cost < dis[nx][ny]) {
                    dis[nx][ny] = cost;
                    if (grid[nx][ny] == 0) {
                        q.AddFirst(new int[] { nx, ny });
                    } else {
                        q.AddLast(new int[] { nx, ny });
                    }
                }
            }
        }
        return false;
    }
}