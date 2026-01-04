class Solution:
    def sumFourDivisors(self, nums: List[int]) -> int:
        ans = 0

        for x in nums:
            n = x
            p = q = cnt = 0

            i = 2
            while i * i <= n and cnt <= 2:
                if n % i == 0:
                    cnt += 1
                    if cnt == 1:
                        p = i
                    else:
                        q = i
                    while n % i == 0:
                        n //= i
                i += 1

            if n > 1:
                cnt += 1
                if cnt == 1:
                    p = n
                else:
                    q = n

            if cnt == 2 and p * q == x:
                ans += 1 + p + q + x
            elif cnt == 1 and p * p * p == x:
                ans += 1 + p + p * p + x

        return ans