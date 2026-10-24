static int min(int a, int b) { return a < b ? a : b; }

static int max(int a, int b) { return a > b ? a : b; }

static int calculateDayOfYear(const char* day, const int* prefixSum) {
    int month = (day[0] - '0') * 10 + day[1] - '0';
    int date = (day[3] - '0') * 10 + day[4] - '0';
    return prefixSum[month - 1] + date;
}

int countDaysTogether(char* arriveAlice, char* leaveAlice, char* arriveBob,
                      char* leaveBob) {
    int datesOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int prefixSum[13];
    prefixSum[0] = 0;
    for (int i = 0; i < 12; i++) {
        prefixSum[i + 1] = prefixSum[i] + datesOfMonths[i];
    }
    int arriveAliceDay = calculateDayOfYear(arriveAlice, prefixSum);
    int leaveAliceDay = calculateDayOfYear(leaveAlice, prefixSum);
    int arriveBobDay = calculateDayOfYear(arriveBob, prefixSum);
    int leaveBobDay = calculateDayOfYear(leaveBob, prefixSum);
    return max(0, min(leaveAliceDay, leaveBobDay) -
                      max(arriveAliceDay, arriveBobDay) + 1);
}