class Solution:
    def maxBottlesDrunk(self, numBottles: int, numExchange: int) -> int:
        res = numBottles
        emptyBottles = numBottles
        fullBottles = 0

        while numExchange <= emptyBottles:
            while emptyBottles >= numExchange:
                fullBottles += 1
                emptyBottles -= numExchange
                numExchange += 1

            res += fullBottles
            emptyBottles += fullBottles
            fullBottles = 0

        return res