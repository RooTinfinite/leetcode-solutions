import bisect

class Solution(object):
    def kthRemainingInteger(self, nums, queries):
        """
        :type nums: List[int]
        :type queries: List[List[int]]
        :rtype: List[int]
        """
        n = len(nums)
        idx = []
        evens = []
        for i, num in enumerate(nums):
            if num % 2 == 0:
                idx.append(i)
                evens.append(num)

        def isPos(i, j, k, target):
            z = bisect.bisect_right(evens, target, lo=i, hi=j+1)
            x = z - i
            y = target // 2 - x
            return y >= k

        res = []
        for l, r, k in queries:
            i = bisect.bisect_left(idx, l)
            j = bisect.bisect_right(idx, r) - 1
            if i > j:
                res.append(2 * k)
            else:
                totalBW = j - i + 1
                first, last = evens[i], evens[j]
                before = first // 2 - 1
                if k <= before:
                    res.append(2 * k)
                else:
                    s, e = 1, k + totalBW
                    ans = 0
                    while s <= e:
                        mid = (s + e) // 2
                        target = mid * 2

                        if isPos(i, j, k, target):
                            ans = target
                            e = mid - 1
                        else:
                            s = mid + 1

                    res.append(ans)

        return res