class Solution {

    public int countCompleteDayPairs(int[] hours) {
        int[] arr = new int[24];
        int count = 0;

        for (int num : hours) {
            int remainder = num % 24;
            int target = (remainder == 0) ? 0 : 24 - remainder;
            count += arr[target];
            arr[remainder]++;
        }

        return count;
    }
}