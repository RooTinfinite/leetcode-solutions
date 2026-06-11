class Solution {
    public int[] minDistinctFreqPair(int[] nums) {
        HashMap<Integer, Integer> freq = new HashMap<>();
        for (int x : nums) 
            freq.put(x, freq.getOrDefault(x, 0) + 1);

        int d = freq.size();
        int[] vals = new int[d];
        int idx = 0;
        for (int v : freq.keySet()) 
            vals[idx++] = v;
        Arrays.sort(vals);

        for (int i = 0; i < d; i++) {
            int x = vals[i];
            for (int j = i + 1; j < d; j++) {
                int y = vals[j];
                if (freq.get(x) != freq.get(y)) 
                    return new int[]{x, y};
            }
        }
        return new int[]{-1, -1};
    }
}