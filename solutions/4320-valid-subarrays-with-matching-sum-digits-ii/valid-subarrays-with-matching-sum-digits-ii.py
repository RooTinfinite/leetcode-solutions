MAX_SUM_LIMIT = 10**14

class Solution:
    def countValidSubarrays(self, nums: list[int], x: int) -> int:
        remBuckets = [[] for _ in range(10)]
        remBuckets[0].append(0)

        prefSum = res = 0

        for num in nums:
            prefSum += num

            targetRem = (prefSum - x + 10) % 10
            candidates = remBuckets[targetRem]

            pow10 = 1
            while pow10 <= prefSum:
                upperBound = prefSum - (x * pow10)
                lowerBound = prefSum - ((x + 1) * pow10) + 1

                if upperBound >= 0:
                    left  = bisect_left(candidates, lowerBound)
                    right = bisect_right(candidates, upperBound)
                    res += (right - left)

                if pow10 > MAX_SUM_LIMIT: break
                pow10 *= 10

            remBuckets[prefSum % 10].append(prefSum)

        return res