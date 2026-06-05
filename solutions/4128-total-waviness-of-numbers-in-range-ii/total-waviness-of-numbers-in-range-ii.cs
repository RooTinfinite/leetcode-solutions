public class Solution {
    private class State {
        public int prev, curr, tight, lead;
        public long cnt, sum;

        public State(int prev, int curr, int tight, int lead, long cnt,
                     long sum) {
            this.prev = prev;
            this.curr = curr;
            this.tight = tight;
            this.lead = lead;
            this.cnt = cnt;
            this.sum = sum;
        }
    }

    private long Solve(long num) {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }
        string s = num.ToString();
        int n = s.Length;

        List<State> currStates = new List<State>();
        // digit 10 represents the invalid state when there is a leading zero
        currStates.Add(new State(10, 10, 1, 1, 1, 0));

        for (int pos = 0; pos < n; ++pos) {
            int limit = s[pos] - '0';
            long[,,,] cnt = new long[2, 2, 11, 11];
            long[,,,] sum = new long[2, 2, 11, 11];

            foreach (State st in currStates) {
                int maxDigit = st.tight == 1 ? limit : 9;
                for (int digit = 0; digit <= maxDigit; ++digit) {
                    int newLead = (st.lead == 1 && digit == 0) ? 1 : 0;
                    int newPrev = st.curr;
                    int newCurr = newLead == 1 ? 10 : digit;
                    int newTight = (st.tight == 1 && digit == maxDigit) ? 1 : 0;

                    long add = 0;
                    // calculate fluctuation only when there are three
                    // significant digits (both prev and curr are valid and not
                    // leading zeros)
                    if (newLead == 0 && st.prev != 10 && st.curr != 10) {
                        if ((st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight, newLead, newPrev, newCurr] += st.cnt;
                    sum[newTight, newLead, newPrev, newCurr] += st.sum + add;
                }
            }

            // collect legal states
            List<State> nextStates = new List<State>();
            for (int tight = 0; tight < 2; ++tight) {
                for (int lead = 0; lead < 2; ++lead) {
                    for (int prev = 0; prev <= 10; ++prev) {
                        for (int curr = 0; curr <= 10; ++curr) {
                            long c = cnt[tight, lead, prev, curr];
                            long sVal = sum[tight, lead, prev, curr];
                            // if the current state is valid, proceed to the
                            // next round of calculation
                            if (c != 0) {
                                nextStates.Add(new State(prev, curr, tight,
                                                         lead, c, sVal));
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        long ans = 0;
        foreach (State st in currStates) {
            ans += st.sum;
        }
        return ans;
    }

    public long TotalWaviness(long num1, long num2) {
        return Solve(num2) - Solve(num1 - 1);
    }
}