class Solution {
    public int firstUniqueFreq(int[] nums) {
        Map<Integer, Integer> counter = new HashMap<>();

        for (int num : nums) {
            counter.put(num, counter.getOrDefault(num, 0) + 1);
        }

        Map<Integer, Integer> freq = new HashMap<>();

        for (int current : counter.keySet()) {
            int count = counter.get(current);
            freq.put(count, freq.getOrDefault(count, 0) + 1);
        }

        for (int num : nums) {
            int count = counter.get(num);
            if (freq.get(count) == 1) return num;
        }

        return -1;
    }
}