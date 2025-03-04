class Solution:
    def checkPowersOfThree(self, n: int) -> bool:
        return self._check_powers_of_three_helper(0, n)

    def _check_powers_of_three_helper(self, power: int, n: int) -> bool:
        # Base case: if n becomes 0, we have successfully formed the sum
        if n == 0:
            return True

        # If the current power of 3 exceeds n, we can't use it, so return false
        if 3**power > n:
            return False

        # Option 1: Include the current power of 3 and subtract it from n
        add_power = self._check_powers_of_three_helper(power + 1, n - 3**power)

        # Option 2: Skip the current power of 3 and try with the next power
        skip_power = self._check_powers_of_three_helper(power + 1, n)

        # Return true if either option leads to a valid solution
        return add_power or skip_power