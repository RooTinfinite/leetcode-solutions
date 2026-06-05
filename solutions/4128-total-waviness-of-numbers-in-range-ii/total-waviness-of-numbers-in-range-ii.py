class Solution:
    def solve(self, num: int) -> int:
        # if the number has fewer than 3 digits, the fluctuation value is 0
        if num < 100:
            return 0
        s = str(num)
        n = len(s)

        # digit 10 represents the invalid state when there is a leading zero
        curr_states = [
            (10, 10, 1, 1, 1, 0)
        ]  # (prev, curr, tight, lead, cnt, sum)

        for pos in range(n):
            limit = int(s[pos])
            cnt = [
                [[[0] * 11 for _ in range(11)] for _ in range(2)]
                for _ in range(2)
            ]
            sum_arr = [
                [[[0] * 11 for _ in range(11)] for _ in range(2)]
                for _ in range(2)
            ]

            for prev, curr, tight, lead, c, s_val in curr_states:
                max_digit = limit if tight else 9
                for digit in range(max_digit + 1):
                    new_lead = 1 if (lead and digit == 0) else 0
                    new_prev = curr
                    new_curr = 10 if new_lead else digit
                    new_tight = 1 if (tight and digit == max_digit) else 0

                    add = 0
                    # calculate fluctuation only when there are three significant digits (both prev and curr are valid and not leading zeros)
                    if not new_lead and prev != 10 and curr != 10:
                        if (prev < curr and curr > digit) or (
                            prev > curr and curr < digit
                        ):
                            add = c

                    cnt[new_tight][new_lead][new_prev][new_curr] += c
                    sum_arr[new_tight][new_lead][new_prev][new_curr] += (
                        s_val + add
                    )

            # collect legal states
            next_states = []
            for tight in range(2):
                for lead in range(2):
                    for prev in range(11):
                        for cur in range(11):
                            c = cnt[tight][lead][prev][cur]
                            if c != 0:
                                next_states.append(
                                    (
                                        prev,
                                        cur,
                                        tight,
                                        lead,
                                        c,
                                        sum_arr[tight][lead][prev][cur],
                                    )
                                )
            curr_states = next_states

        # sum of fluctuation values of all valid states
        ans = 0
        for _, _, _, _, _, s_val in curr_states:
            ans += s_val
        return ans

    def totalWaviness(self, num1: int, num2: int) -> int:
        return self.solve(num2) - self.solve(num1 - 1)