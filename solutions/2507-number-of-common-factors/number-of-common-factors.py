class Solution:
    def commonFactors(self, a: int, b: int) -> int:
        c =0
        for x in range(1,min(a,b) + 1):
            if a % x==0 and b % x== 0:
                c +=1
        return c