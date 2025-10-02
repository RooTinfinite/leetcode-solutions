class Solution {
    public long shiftDistance(String s, String t, int[] nextCost, int[] previousCost) {
        int n = s.length();
        long res = 0;
        long[] next = new long[26], prev = new long[26];
        next[0] = nextCost[0];
        prev[0] = previousCost[0];
        for (int i = 1; i < 26; i++){
            next[i] = (long)nextCost[i] + next[i - 1];
            prev[i] = (long)previousCost[i] + prev[i - 1];
        }
        for (int i = 0; i < n; i++){
            int a = s.charAt(i) - 'a', b = t.charAt(i) - 'a';
            if (a == b) continue;
            long forward = 0, back = 0;
            if (b < a){
                forward += next[25] - (a != 0 ? next[a - 1] : 0); // forward
                if (b != 0) forward += next[b - 1];
                back = prev[a] - prev[b]; // back
            }
            else{
                forward += next[b - 1]; // forward
                if (a != 0) forward -= next[a - 1];
                back += prev[a] + prev[25] - prev[b]; // back
            }
            res += Math.min(forward, back);
        }
        return res;
    }
}