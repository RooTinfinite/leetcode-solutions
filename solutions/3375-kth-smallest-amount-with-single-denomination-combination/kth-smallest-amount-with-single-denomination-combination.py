class Solution:
    def findKthSmallest(self, coins: List[int], k: int) -> int:
        coins.sort()
        new_coins = []
        for x in coins:
            if all(x % y for y in new_coins):
                new_coins.append(x)
        coins = new_coins

        n = len(coins)
        m = 1 << n
        lcm = [1] * m

        left = k
        right = coins[0] * k + 1

        for mask in range(1, m):
            pre_mask = mask & (mask - 1)
            i = (mask & -mask).bit_length() - 1

            tmp = lcm[pre_mask] // gcd(lcm[pre_mask], coins[i])
            if tmp <= right // coins[i]:
                lcm[mask] = tmp * coins[i]
            else:
                lcm[mask] = right + 1

        def get(x: int) -> int:
            count = 0
            for mask in range(1, m):
                if lcm[mask] > x:
                    continue
                if mask.bit_count() & 1:
                    count += x // lcm[mask]
                else:
                    count -= x // lcm[mask]

            return count

        while left < right:
            mid = (left + right) // 2
            if get(mid) >= k:
                right = mid
            else:
                left = mid + 1

        return left