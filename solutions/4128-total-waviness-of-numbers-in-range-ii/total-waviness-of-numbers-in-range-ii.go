type State struct {
    prev, curr, tight, lead int
    cnt, sum                 int64
}

func solve(num int64) int64 {
    // if the number has fewer than 3 digits, the fluctuation value is 0
    if num < 100 {
        return 0
    }
    s := fmt.Sprintf("%d", num)
    n := len(s)

    currStates := []State{{10, 10, 1, 1, 1, 0}}

    for pos := 0; pos < n; pos++ {
        limit := int(s[pos] - '0')
        cnt := [2][2][11][11]int64{}
        sum := [2][2][11][11]int64{}

        for _, st := range currStates {
            maxDigit := limit
            if st.tight == 0 {
                maxDigit = 9
            }
            for digit := 0; digit <= maxDigit; digit++ {
                newLead := 0
                if st.lead == 1 && digit == 0 {
                    newLead = 1
                }
                newPrev := st.curr
                newCurr := digit
                if newLead == 1 {
                    newCurr = 10
                }
                newTight := 0
                if st.tight == 1 && digit == maxDigit {
                    newTight = 1
                }

                add := int64(0)
                // calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                if newLead == 0 && st.prev != 10 && st.curr != 10 {
                    if (st.prev < st.curr && st.curr > digit) ||
                        (st.prev > st.curr && st.curr < digit) {
                        add = st.cnt
                    }
                }

                cnt[newTight][newLead][newPrev][newCurr] += st.cnt
                sum[newTight][newLead][newPrev][newCurr] += st.sum + add
            }
        }

        // collect legal states
        nextStates := []State{}
        for tight := 0; tight < 2; tight++ {
            for lead := 0; lead < 2; lead++ {
                for prev := 0; prev <= 10; prev++ {
                    for curr := 0; curr <= 10; curr++ {
                        c := cnt[tight][lead][prev][curr]
                        sVal := sum[tight][lead][prev][curr]
                        // if the current state is valid, proceed to the next round of calculation
                        if c != 0 {
                            nextStates = append(nextStates, State{prev, curr, tight, lead, c, sVal})
                        }
                    }
                }
            }
        }
        currStates = nextStates
    }

    // sum of fluctuation values of all valid states
    var ans int64 = 0
    for _, st := range currStates {
        ans += st.sum
    }
    return ans
}

func totalWaviness(num1 int64, num2 int64) int64 {
    return solve(num2) - solve(num1-1)
}