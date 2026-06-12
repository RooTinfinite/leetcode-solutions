class Solution {
    // time = O(nlogn), space = O(n)
    public int maxRequests(int[][] requests, int k, int window) {
        int n = requests.length, res = 0;
        HashMap<Integer, List<Integer>> map = new HashMap<>();
        for (int[] r : requests) {
            int id = r[0], t = r[1];
            map.putIfAbsent(id, new ArrayList<>());
            map.get(id).add(t);
        }
        for (List<Integer> v : map.values()) {
            Collections.sort(v);
            res += get(v, k, window);
        }
        return res;
    }

    private int get(List<Integer> q, int k, int window) {
        int n = q.size(), res = n;
        boolean[] st = new boolean[n];
        for (int i = 0, j = 0, t = 0; i < n; i++) {
            t++;
            st[i] = true;
            while (q.get(i) - q.get(j) > window) {
                if (st[j]) t--;
                j++;
            }
            if (t > k) {
                st[i] = false;
                t--;
                res--;
            }
        }
        return res;
    }
}