class Solution:
    def numberOfWays(self, s: str) -> int:
        zeros = s.count('0')
        ones = len(s) - zeros
        zeroPrefix = onePrefix = res = 0
        for c in s:
            if c == '0':
                res += onePrefix * (ones - onePrefix)
                zeroPrefix += 1
            else:
                res += zeroPrefix * (zeros - zeroPrefix)
                onePrefix += 1
        
        return res