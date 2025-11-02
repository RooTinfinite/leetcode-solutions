class Solution:
    def numberOfPatterns(self, m: int, n: int) -> int:
        jump = [[0] * 10 for _ in range(10)]

        # Initialize the jump over numbers for all valid jumps
        jump[1][3] = jump[3][1] = 2
        jump[4][6] = jump[6][4] = 5
        jump[7][9] = jump[9][7] = 8
        jump[1][7] = jump[7][1] = 4
        jump[2][8] = jump[8][2] = 5
        jump[3][9] = jump[9][3] = 6
        jump[1][9] = jump[9][1] = jump[3][7] = jump[7][3] = 5

        visited_numbers = 0
        total_patterns = 0
        dp = [[-1] * (1 << 10) for _ in range(10)]

        # Count patterns starting from corner numbers (1, 3, 7, 9) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(
                1, 1, m, n, jump, visited_numbers, dp
            )
            * 4
        )

        # Count patterns starting from edge numbers (2, 4, 6, 8) and multiply by 4 due to symmetry
        total_patterns += (
            self._count_patterns_from_number(
                2, 1, m, n, jump, visited_numbers, dp
            )
            * 4
        )

        # Count patterns starting from the center number (5)
        total_patterns += self._count_patterns_from_number(
            5, 1, m, n, jump, visited_numbers, dp
        )

        return total_patterns

    def _count_patterns_from_number(
        self,
        current_number: int,
        current_length: int,
        min_length: int,
        max_length: int,
        jump: list,
        visited_numbers: int,
        dp: list,
    ) -> int:
        # Base case: if current pattern length exceeds max_length, stop exploring
        if current_length > max_length:
            return 0

        if dp[current_number][visited_numbers] != -1:
            return dp[current_number][visited_numbers]

        valid_patterns = 0
        # If current pattern length is within the valid range, count it
        if current_length >= min_length:
            valid_patterns += 1

        visited_numbers = self._set_bit(visited_numbers, current_number)

        # Explore all possible next numbers
        for next_number in range(1, 10):
            jump_over_number = jump[current_number][next_number]
            # Check if the next number is unvisited and either:
            # 1. There's no number to jump over, or
            # 2. The number to jump over has been visited
            if not self._is_set(visited_numbers, next_number) and (
                jump_over_number == 0
                or self._is_set(visited_numbers, jump_over_number)
            ):
                valid_patterns += self._count_patterns_from_number(
                    next_number,
                    current_length + 1,
                    min_length,
                    max_length,
                    jump,
                    visited_numbers,
                    dp,
                )

        # Backtrack: unmark the current number before returning
        visited_numbers = self._clear_bit(visited_numbers, current_number)

        dp[current_number][visited_numbers] = valid_patterns
        return valid_patterns

    def _set_bit(self, num: int, position: int) -> int:
        num |= 1 << (position - 1)
        return num

    def _clear_bit(self, num: int, position: int) -> int:
        num ^= 1 << (position - 1)
        return num

    def _is_set(self, num: int, position: int) -> bool:
        bit_at_position = (num >> (position - 1)) & 1
        return bit_at_position == 1