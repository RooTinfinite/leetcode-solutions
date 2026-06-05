typedef struct {
    int prev, curr, tight, lead;
    long long cnt, sum;
} State;

long long solve(long long num) {
    // if the number has fewer than 3 digits, the fluctuation value is 0
    if (num < 100) {
        return 0;
    }

    char s[20];
    sprintf(s, "%lld", num);
    int n = strlen(s);

    State currStates[500];
    int currSize = 0;

    // digit 10 represents the invalid state when there is a leading zero
    currStates[currSize++] = (State){10, 10, 1, 1, 1, 0};

    for (int pos = 0; pos < n; ++pos) {
        int limit = s[pos] - '0';

        // use a four-dimensional array for temporary storage, dimensions:
        // [tight][lead][prev][curr]
        long long cnt[2][2][11][11] = {0};
        long long sum[2][2][11][11] = {0};

        for (int i = 0; i < currSize; ++i) {
            State st = currStates[i];
            int maxDigit = st.tight ? limit : 9;

            for (int digit = 0; digit <= maxDigit; ++digit) {
                int newLead = (st.lead && digit == 0) ? 1 : 0;
                int newPrev = st.curr;
                int newCurr = newLead ? 10 : digit;
                int newTight = (st.tight && digit == maxDigit) ? 1 : 0;

                long long add = 0;
                // calculate fluctuation only when there are three significant
                // digits (both prev and curr are valid and not leading zeros)
                if (!newLead && st.prev != 10 && st.curr != 10) {
                    if ((st.prev < st.curr && st.curr > digit) ||
                        (st.prev > st.curr && st.curr < digit)) {
                        add = st.cnt;
                    }
                }

                cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                sum[newTight][newLead][newPrev][newCurr] += st.sum + add;
            }
        }

        // collect legal states
        State nextStates[500];
        int nextSize = 0;

        for (int tight = 0; tight < 2; ++tight) {
            for (int lead = 0; lead < 2; ++lead) {
                for (int prev = 0; prev <= 10; ++prev) {
                    for (int curr = 0; curr <= 10; ++curr) {
                        long long c = cnt[tight][lead][prev][curr];
                        long long s_val = sum[tight][lead][prev][curr];
                        // if the current state is valid, proceed to the next
                        // round of calculation
                        if (c != 0) {
                            nextStates[nextSize++] =
                                (State){prev, curr, tight, lead, c, s_val};
                        }
                    }
                }
            }
        }

        // switch to the next round state
        memcpy(currStates, nextStates, nextSize * sizeof(State));
        currSize = nextSize;
    }

    // sum of fluctuation values of all valid states
    long long ans = 0;
    for (int i = 0; i < currSize; ++i) {
        ans += currStates[i].sum;
    }
    return ans;
}

long long totalWaviness(long long num1, long long num2) {
    return solve(num2) - solve(num1 - 1);
}