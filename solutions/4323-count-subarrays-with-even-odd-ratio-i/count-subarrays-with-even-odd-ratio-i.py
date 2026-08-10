
class Solution:
    def countRatioSubarrays(self, nums: list[int], 
                            a: int, b: int) -> int:

        n, ans = len(nums), 0

        for i in range(n):
            p, q = 0, 0

            for j in range(i, n):
                p+= b
                if nums[j]%2 == 1:
                    q+= a + b
                if p <= q: ans+= 1

        return ans
    