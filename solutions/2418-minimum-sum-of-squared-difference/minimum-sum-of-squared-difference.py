class Solution:
    def minSumSquareDiff(
        self, nums1: List[int], nums2: List[int], k1: int, k2: int
    ) -> int:
        k = k1 + k2
        n = len(nums1)
        max_dif = 0
        for i in range(n):
            nums1[i] = abs(nums1[i] - nums2[i])
            max_dif = max(max_dif, nums1[i])

        l, r, res = 0, max_dif, 0
        while l <= r:
            mid = (l + r) >> 1
            if sum(num - mid for num in nums1 if num > mid) <= k:
                r = mid - 1
                res = mid
            else:
                l = mid + 1

        for num in nums1:
            if num > res:
                k -= num - res

        nums1.sort(reverse=True)
        ans = 0
        for num in nums1:
            diff = min(num, res)
            if k > 0 and diff > 0:
                diff -= 1
                k -= 1
            ans += diff * diff
        return ans