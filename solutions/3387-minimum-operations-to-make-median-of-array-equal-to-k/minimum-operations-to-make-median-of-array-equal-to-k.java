class Solution {
    public long minOperationsToMakeMedianK(int[] a, int k) {
        Arrays.sort(a);
        int n = a.length;
        long answer = 0;
        for(int i = 0; i < n; i++) {
            if(i < n / 2) {
                answer += (long) Math.max(0, a[i] - k);
            } else if(i == n / 2) {
                answer += (long) Math.abs(k - a[i]);
            } else {
                answer += (long) Math.max(0, k - a[i]);
            }
        }
        return answer;
    }
}