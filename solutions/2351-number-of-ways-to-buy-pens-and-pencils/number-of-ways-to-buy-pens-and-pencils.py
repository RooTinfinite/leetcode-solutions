class Solution:
    def waysToBuyPensPencils(self, total: int, cost1: int, cost2: int) -> int:

        c = 0
        ran =  total // cost1
        rem = total % cost1
        for i in range(ran+1):
            num = total - (i * cost1)
            
            nnum = num // cost2
            c += nnum + 1

        return c    