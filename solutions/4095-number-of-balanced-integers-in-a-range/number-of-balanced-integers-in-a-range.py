class Solution:
    def solve(self, num: int) -> int:
        digits = [0, *map(int, str(num))]

        @cache
        def dp(i: int = 0, diff: int = 0, digitlim: bool = True) -> int:
            # We reached end of number
            if i == len(digits):
                return int(diff == 0)

            # Calculate current digit values
            maxdigit = digits[i] if digitlim else 9
            possign = (2 * int(i % 2) - 1)

            result = 0
            for digit in range(maxdigit + 1):
                # Update state and call dp for the next digit
                diff_next = diff + digit * possign
                digitlim_next = digit == maxdigit and digitlim
                result += dp(i + 1, diff_next, digitlim_next)

            return result

        return dp()

    def countBalanced(self, low: int, high: int) -> int:
        return self.solve(high) - self.solve(low - 1)