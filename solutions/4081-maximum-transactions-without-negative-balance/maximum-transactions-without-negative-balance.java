import java.util.PriorityQueue;

public class Solution {

    public int maxTransactions(int[] transactions) {
        long valueOfTransactions = 0;
        int numberOfTransactions = 0;
        PriorityQueue<Integer> minHeapNegativeValuesIncludedInTransactions = new PriorityQueue<>();

        for (int value : transactions) {

            if (value >= 0) {
                ++numberOfTransactions;
                valueOfTransactions += value;
                continue;
            }

            if (valueOfTransactions + value >= 0) {
                minHeapNegativeValuesIncludedInTransactions.add(value);
                ++numberOfTransactions;
                valueOfTransactions += value;
                continue;
            }

            if (!minHeapNegativeValuesIncludedInTransactions.isEmpty() && minHeapNegativeValuesIncludedInTransactions.peek() < value) {
                valueOfTransactions += value - minHeapNegativeValuesIncludedInTransactions.poll();
                minHeapNegativeValuesIncludedInTransactions.add(value);
            }
        }

        return numberOfTransactions;
    }
}