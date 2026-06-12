class Solution:
    def isDigitorialPermutation(self, n: int) -> bool:
        # Precalculate factorials of digits from 0 to 9
        facts = [1]
        for digit in range(1, 10):
            facts.append(facts[-1] * digit)

        digits_sum = sum(facts[digit] for digit in map(int, str(n)))
        return Counter(str(digits_sum)) == Counter(str(n))