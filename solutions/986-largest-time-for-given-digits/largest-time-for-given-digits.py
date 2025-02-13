class Solution:
    def largestTimeFromDigits(self, A: List[int]) -> str:
        return next((f'{h1}{h2}:{m1}{m2}' for h1, h2, m1, m2 in permutations(sorted(A, reverse=True)) if h1 * 10 + h2 < 24 and m1 * 10 + m2 < 60), '')