public class Solution {
    public int CountDaysTogether(string arriveAlice, string leaveAlice,
                                 string arriveBob, string leaveBob) {
        int[] datesOfMonths = { 31, 28, 31, 30, 31, 30,
                                31, 31, 30, 31, 30, 31 };
        int[] prefixSum = new int[13];
        for (int i = 0; i < 12; i++) {
            prefixSum[i + 1] = prefixSum[i] + datesOfMonths[i];
        }

        int arriveAliceDay = CalculateDayOfYear(arriveAlice, prefixSum);
        int leaveAliceDay = CalculateDayOfYear(leaveAlice, prefixSum);
        int arriveBobDay = CalculateDayOfYear(arriveBob, prefixSum);
        int leaveBobDay = CalculateDayOfYear(leaveBob, prefixSum);
        return Math.Max(0, Math.Min(leaveAliceDay, leaveBobDay) -
                               Math.Max(arriveAliceDay, arriveBobDay) + 1);
    }

    private int CalculateDayOfYear(string day, int[] prefixSum) {
        int month = int.Parse(day.Substring(0, 2));
        int date = int.Parse(day.Substring(3));
        return prefixSum[month - 1] + date;
    }
}