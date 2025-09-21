class Solution {
    public int closestTarget(String[] W, String T, int s) {
        int a = Integer.MAX_VALUE, n = W.length;
        for (int i = 0; i < n; i++) {
            if (W[i].equals(T)) {
                int d = Math.abs(i - s);
                a = Math.min(a, Math.min(d, n - d));
            }
        }
        return a == Integer.MAX_VALUE ? -1 : a;
    }
}