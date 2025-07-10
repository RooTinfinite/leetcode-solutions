class Solution {
    public List<Long> maximumEvenSplit(long finalSum) {
        List<Long> result = new ArrayList<>();
        if (finalSum % 2 != 0) return result;

        long current = 2;
        while (finalSum >= current) {
            result.add(current);
            finalSum -= current;
            current += 2;
        }

        if (finalSum > 0) {
            result.set(result.size() - 1, result.get(result.size() - 1) + finalSum);
        }
        return result;
    }
}