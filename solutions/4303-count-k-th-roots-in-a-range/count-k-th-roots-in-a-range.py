class Solution:

    def possible(self, mid, k, n):

        # handle 0 separately
        if mid == 0:
            return True

        ans = 1

        for _ in range(k):
            # avoid overflow
            if ans > n // mid:
                return False

            ans *= mid

        return ans <= n

    # floor(n^(1/k))
    def kthRoot(self, n, k):

        low = 0
        high = n

        ans = 0

        while low <= high:
            mid = low + (high - low) // 2

            if self.possible(mid, k, n):
                ans = mid
                low = mid + 1
            else:
                high = mid - 1

        return ans

    def countKthRoots(self, l: int, r: int, k: int) -> int:
        right = self.kthRoot(r, k)
        left = self.kthRoot(l - 1, k)

        ans = right - left

        # include 0
        if l == 0:
            ans += 1

        return ans