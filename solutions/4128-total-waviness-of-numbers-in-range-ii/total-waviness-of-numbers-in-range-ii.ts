function totalWaviness(num1: number, num2: number): number {
    // calculate the sum of the volatility values of all numbers in [0, num]
    const solve = (num: number): number => {
        // if the number has fewer than 3 digits, the fluctuation value is 0
        if (num < 100) {
            return 0;
        }

        const s: string = num.toString();
        const n: number = s.length;

        interface State {
            prev: number;
            curr: number;
            tight: number;
            lead: number;
            cnt: number;
            sum: number;
        }

        let currStates: State[] = [];
        // digit 10 represents the invalid state when there is a leading zero
        currStates.push({
            prev: 10,
            curr: 10,
            tight: 1,
            lead: 1,
            cnt: 1,
            sum: 0,
        });
        for (let pos = 0; pos < n; ++pos) {
            const limit: number = parseInt(s[pos]);

            // use a four-dimensional array for temporary storage, dimensions: [tight][lead][prev][curr]
            const cnt: number[][][][] = Array(2)
                .fill(null)
                .map(() =>
                    Array(2)
                        .fill(null)
                        .map(() =>
                            Array(11)
                                .fill(null)
                                .map(() => Array(11).fill(0)),
                        ),
                );
            const sumArr: number[][][][] = Array(2)
                .fill(null)
                .map(() =>
                    Array(2)
                        .fill(null)
                        .map(() =>
                            Array(11)
                                .fill(null)
                                .map(() => Array(11).fill(0)),
                        ),
                );

            for (const st of currStates) {
                const maxDigit: number = st.tight ? limit : 9;

                for (let digit = 0; digit <= maxDigit; ++digit) {
                    const newLead: number = st.lead && digit === 0 ? 1 : 0;
                    const newPrev: number = st.curr;
                    const newCurr: number = newLead ? 10 : digit;
                    const newTight: number =
                        st.tight && digit === maxDigit ? 1 : 0;

                    let add: number = 0;
                    // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if (!newLead && st.prev !== 10 && st.curr !== 10) {
                        if (
                            (st.prev < st.curr && st.curr > digit) ||
                            (st.prev > st.curr && st.curr < digit)
                        ) {
                            add = st.cnt;
                        }
                    }

                    cnt[newTight][newLead][newPrev][newCurr] += st.cnt;
                    sumArr[newTight][newLead][newPrev][newCurr] += st.sum + add;
                }
            }

            // collect legal states
            const nextStates: State[] = [];
            for (let tight = 0; tight < 2; ++tight) {
                for (let lead = 0; lead < 2; ++lead) {
                    for (let prev = 0; prev <= 10; ++prev) {
                        for (let curr = 0; curr <= 10; ++curr) {
                            const c: number = cnt[tight][lead][prev][curr];
                            const sVal: number =
                                sumArr[tight][lead][prev][curr];
                            // if the current state is valid, proceed to the next round of calculation
                            if (c !== 0) {
                                nextStates.push({
                                    prev,
                                    curr,
                                    tight,
                                    lead,
                                    cnt: c,
                                    sum: sVal,
                                });
                            }
                        }
                    }
                }
            }

            currStates = nextStates;
        }

        // sum of fluctuation values of all valid states
        let ans: number = 0;
        for (const st of currStates) {
            ans += st.sum;
        }
        return ans;
    };

    return solve(num2) - solve(num1 - 1);
}