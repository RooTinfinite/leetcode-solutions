class Solution:         
    def minimumPerimeter(self, neededApples: int) -> int:

        f = lambda x: x*(x*(4*x+6)+2)
        left, right = 1, 65536

        while left < right:

            mid = (left + right)//2

            if f(mid) >= neededApples: right = mid
            else: left = mid + 1

        return 8*left