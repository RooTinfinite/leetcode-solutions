class Solution:
    # Check if the current sequence matches the pattern of 'I' and 'D'
    def check(self, number_sequence: str, pattern: str) -> bool:
        for index in range(len(pattern)):
            # Ensure the sequence is in increasing order at 'I' positions
            if (
                pattern[index] == "I"
                and number_sequence[index] > number_sequence[index + 1]
            ):
                return False
            # Ensure the sequence is in decreasing order at 'D' positions
            elif (
                pattern[index] == "D"
                and number_sequence[index] < number_sequence[index + 1]
            ):
                return False
        return True

    def smallestNumber(self, pattern: str) -> str:
        pattern_length = len(pattern)

        # Generate sequence "123...n+1"
        number_sequence = "".join(
            str(num) for num in range(1, pattern_length + 2)
        )

        # Use permutations generator
        for permutation in permutations(number_sequence):
            permutation_str = "".join(permutation)
            if self.check(permutation_str, pattern):
                return permutation_str
        return ""