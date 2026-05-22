from math import comb

class Solution:
    def nthSmallest(self, n: int, k: int) -> int:
        result = 0

        for bit in range(50, -1, -1):
            if k == 0: break

            if bit < k:
                result |= (1 << bit)
                k -= 1
            else:
                count = comb(bit, k)

                if n > count:
                    result |= (1 << bit)
                    n -= count
                    k -= 1

        return result