class Solution:
    def findValidPair(self, s: str) -> str:

        ctr = Counter(s)
        valid = set(digit for digit in ctr if str(ctr[digit]) == digit)
        
        for digit1, digit2 in pairwise(s):
            if digit1 == digit2: continue
            if digit1 in valid and digit2 in valid:
                return digit1 + digit2

        return ""