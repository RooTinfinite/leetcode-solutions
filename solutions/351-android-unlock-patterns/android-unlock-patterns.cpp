class Solution {
public:
    int numberOfPatterns(int m, int n) {
        int jump[10][10] = {0};

        // Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2;
        jump[4][6] = jump[6][4] = 5;
        jump[7][9] = jump[9][7] = 8;
        jump[1][7] = jump[7][1] = 4;
        jump[2][8] = jump[8][2] = 5;
        jump[3][9] = jump[9][3] = 6;
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5;

        int visitedNumbers = 0;
        int totalPatterns = 0;
        int dp[10][1 << 10] = {0};
        memset(dp, -1, sizeof(dp));

        // Count patterns starting from corner numbers (1, 3, 7, 9) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(1, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from edge numbers (2, 4, 6, 8) and multiply
        // by 4 due to symmetry
        totalPatterns +=
            countPatternsFromNumber(2, 1, m, n, jump, visitedNumbers, dp) * 4;

        // Count patterns starting from the center number (5)
        totalPatterns +=
            countPatternsFromNumber(5, 1, m, n, jump, visitedNumbers, dp);

        return totalPatterns;
    }

private:
    int countPatternsFromNumber(int currentNumber, int currentLength,
                                int minLength, int maxLength, int jump[10][10],
                                int visitedNumbers, int dp[10][1 << 10]) {
        // Base case: if current pattern length exceeds maxLength, stop
        // exploring
        if (currentLength > maxLength) return 0;

        if (dp[currentNumber][visitedNumbers] != -1)
            return dp[currentNumber][visitedNumbers];

        int validPatterns = 0;
        // If current pattern length is within the valid range, count it
        if (currentLength >= minLength) {
            validPatterns++;
        }

        visitedNumbers = setBit(visitedNumbers, currentNumber);

        // Explore all possible next numbers
        for (int nextNumber = 1; nextNumber <= 9; nextNumber++) {
            int jumpOverNumber = jump[currentNumber][nextNumber];
            // Check if the next number is unvisited and either:
            // 1. There's no number to jump over, or
            // 2. The number to jump over has been visited
            if (!isSet(visitedNumbers, nextNumber) &&
                (jumpOverNumber == 0 ||
                 isSet(visitedNumbers, jumpOverNumber))) {
                validPatterns += countPatternsFromNumber(
                    nextNumber, currentLength + 1, minLength, maxLength, jump,
                    visitedNumbers, dp);
            }
        }

        // Backtrack: unmark the current number before returning
        visitedNumbers = clearBit(visitedNumbers, currentNumber);

        return dp[currentNumber][visitedNumbers] = validPatterns;
    }

    int setBit(int num, int position) {
        num |= 1 << (position - 1);
        return num;
    }

    int clearBit(int num, int position) {
        num ^= 1 << (position - 1);
        return num;
    }

    bool isSet(int num, int position) {
        int bitAtPosition = (num >> (position - 1)) & 1;
        return bitAtPosition == 1;
    }
};