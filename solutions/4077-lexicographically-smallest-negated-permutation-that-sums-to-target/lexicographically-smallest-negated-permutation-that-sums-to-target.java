class Solution {
    long sumUpTo(long x) {
        return x * (x + 1) / 2;
    }

    public int[] lexSmallestNegatedPerm(int n, long target) {
        long S = sumUpTo(n);
        if (target < -S || target > S) return new int[0];

        java.util.List<Integer> v = new java.util.ArrayList<>();

        for (int i = n; i >= 1; i--) {
            if (sumUpTo(i - 1) - i >= target) {
                target += i;
                v.add(-i);
            } else {
                target -= i;
                v.add(i);
            }
        }

        if (target != 0) return new int[0];

        v.sort(null);

        int[] res = new int[v.size()];
        for (int i = 0; i < v.size(); i++) res[i] = v.get(i);
        return res;
    }
}