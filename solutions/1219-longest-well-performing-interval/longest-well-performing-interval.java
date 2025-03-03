class Solution {

    public static final int BALANCE_WORKING_TIME = 8;

    public int longestWPI(int[] hours) {
        Map<Integer, Integer> map = new HashMap<>();
        // map.put(0, -1);
        int total = 0, maxLength = 0;
        for (int i = 0; i < hours.length; i++) {
            total += hours[i] > BALANCE_WORKING_TIME ? 1 : -1;
            if (total > 0) {
                maxLength = i + 1;
            } else if (map.containsKey(total - 1)) {
                maxLength = Math.max(maxLength, i - map.get(total - 1));
            }
            map.putIfAbsent(total, i);
        }

        return maxLength;
    }
}