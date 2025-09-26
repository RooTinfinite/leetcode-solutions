class Solution {
    public int maximizeSquareArea(int m, int n, int[] hFences, int[] vFences) {
        Set<Integer> hs = buildSqLengthCandidates(m, hFences), ws = buildSqLengthCandidates(n, vFences);
        long max = 0, mod = 1000000007;
        for (int i : hs) {
            if (ws.contains(i)) {
                max = Math.max(i, max);
            }
        }
        int result = (int) (max * max % mod);
        return result == 0 ? -1 : result;
    }

    private Set<Integer> buildSqLengthCandidates(int l, int[] fences ) {
        Set<Integer> cands = new HashSet<>();
        Arrays.sort(fences);
        cands.add(l - 1);
        for (int i = 0; i < fences.length; i++) {
            cands.add(fences[i] - 1);
            cands.add(l - fences[i]);
            for (int j =  i + 1; j < fences.length; j++) {
                cands.add(fences[j] - fences[i]);
            }
        }
        return cands;
    }
}