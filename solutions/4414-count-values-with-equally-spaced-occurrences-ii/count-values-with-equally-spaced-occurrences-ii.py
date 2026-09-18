class Solution:
    def countSpecialIntegers(self, nums: list[int]) -> int:

        count = 0

        def track(num):
            i, j, k = (yield), (yield), (yield)
            d = j - i
            if k - j == d:
                nonlocal count
                count += 1
                while k + d == (k := (yield)):
                    pass
                count -= 1
            while True:
                yield

        @cache
        def tracker(num):
            gen = track(num)
            next(gen)
            return gen

        for i, num in enumerate(nums):
            tracker(num).send(i)

        return count