class Solution {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        List<Long> arr = new ArrayList<>();
        for (int potion : potions) {
            arr.add((long) Math.ceil((double) success / potion)); // Use long for large numbers
        }
        Collections.sort(arr);

        int[] res = new int[spells.length];
        for (int i = 0; i < spells.length; i++) {
            int spell = spells[i];
            int l = 0, r = arr.size() - 1, M = 0;
            while (l <= r) {
                int m = l + (r - l) / 2;
                if (arr.get(m) <= spell) {
                    l = m + 1;
                    M = l;
                } else {
                    r = m - 1;
                }
            }
            res[i] = M;
        }

        return res;
    }
}