class Solution {
    public List<Integer> solveQueries(int[] nums, int[] queries) {
        int n = nums.length;
        HashMap<Integer, ArrayList<Integer>> mh = buildMap(nums, n);
        ArrayList<Integer> res = new ArrayList<>();
        for (int q : queries) {
            res.add(solve(mh.get(nums[q]), q, n));
        }
        return res;
    }

    public HashMap<Integer, ArrayList<Integer>> buildMap(int[] nums, int n) {
        HashMap<Integer, ArrayList<Integer>> mh = new HashMap<>();
        for (int i = 0; i < n; i++) {
            if (!mh.containsKey(nums[i])) {
                mh.put(nums[i], new ArrayList<>());
            }
            mh.get(nums[i]).add(i);
        }
        return mh;
    }

    public int solve(ArrayList<Integer> l, int q, int n) {
        if (l == null || l.size() < 2) return -1;
        int pos = binarySearch(l, q);
        int left = pos == 0 ? l.get(l.size() - 1) : l.get(pos - 1);
        int right = pos == l.size() - 1 ? l.get(0) : l.get(pos + 1);
        return Math.min(dist(q, left, n), dist(q, right, n));
    }

    public int binarySearch(ArrayList<Integer> l, int target) {
        int left = 0, right = l.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (l.get(mid) == target) return mid;
            else if (l.get(mid) < target) left = mid + 1;
            else right = mid - 1;
        }
        return left;
    }

    public int dist(int i, int j, int n) {
        int d = Math.abs(i - j);
        return Math.min(d, n - d);
    }
}