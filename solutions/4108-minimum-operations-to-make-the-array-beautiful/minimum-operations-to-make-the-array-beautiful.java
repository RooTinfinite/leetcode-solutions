class Solution {
    public int minOperations(int[] ar) {
        int max = 0;
        for (int e : ar) if (e > max) max = e;
        if (max == 1) return 0;
        int highestPossibleNumber = (max - 1) * 2;
        int[][] best = new int[2][highestPossibleNumber + 1];
        for (int i = 0; i <= highestPossibleNumber; i++) best[0][i] = 1_000_000_000;
        best[0][ar[0]] = 0;
        for (int i = 1; i < ar.length; i++) {
            int[] last = best[(i + 1) % 2], cur = best[i % 2];
            for (int p = 0; p < cur.length; p++) cur[p] = 1_000_000_000;
            for (int prevEnd = 1; prevEnd < last.length; prevEnd++) {
                if (last[prevEnd] >= 1_000_000_000) continue;
                int smallestMult = (ar[i] + prevEnd - 1) / prevEnd * prevEnd;
                for (int v = smallestMult; v < cur.length; v += prevEnd)
                    cur[v] = Math.min(cur[v], last[prevEnd] + v - ar[i]);
            }
        }
        int[] opsReq = best[(ar.length + 1) % 2];
        int min = 1_000_000_000;
        for (int e : opsReq) if (e < min) min = e;
        return min;
    }
}