public class Solution {
    public int[] AssignTasks(int[] servers, int[] tasks) {
        // Busy servers, stored as pairs (t, idx)
        var busy = new PriorityQueue<(int t, int idx), int>();
        // Idle servers, stored as pairs (w, idx)
        var idle = new PriorityQueue<(int w, int idx), (int, int)>(
            Comparer<(int, int)>.Create((a, b) => {
                if (a.Item1 != b.Item1) {
                    return a.Item1 - b.Item1;
                }
                return a.Item2 - b.Item2;
            }));

        for (int i = 0; i < servers.Length; i++) {
            idle.Enqueue((servers[i], i), (servers[i], i));
        }

        int ts = 0;
        int[] ans = new int[tasks.Length];

        for (int i = 0; i < tasks.Length; i++) {
            ts = Math.Max(ts, i);
            Release(busy, idle, servers, ts);
            if (idle.Count == 0) {
                ts = busy.Peek().t;
                Release(busy, idle, servers, ts);
            }

            var server = idle.Dequeue();
            int idx = server.idx;
            ans[i] = idx;
            busy.Enqueue((ts + tasks[i], idx), ts + tasks[i]);
        }

        return ans;
    }

    // Move servers with t<=ts from priority queue busy to priority queue idle
    // one by one
    private void Release(PriorityQueue<(int t, int idx), int> busy,
                         PriorityQueue<(int w, int idx), (int, int)> idle,
                         int[] servers, int ts) {
        while (busy.Count > 0 && busy.Peek().t <= ts) {
            var server = busy.Dequeue();
            int idx = server.idx;
            idle.Enqueue((servers[idx], idx), (servers[idx], idx));
        }
    }
}