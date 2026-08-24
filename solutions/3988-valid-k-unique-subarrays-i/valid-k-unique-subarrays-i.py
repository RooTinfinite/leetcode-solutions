class Solution:
    def validSubarrays(self, nums: list[int], k: int, queries: list[list[int]]) -> list[bool]:        
        n, q = len(nums), len(queries)
        blockSize = max(1, int(sqrt(n)))
        
        queries = [(l, r, i) for i, (l, r) in enumerate(queries)]
        queries.sort(key=lambda x: (x[0] // blockSize, x[1] if (x[0] // blockSize)%2==0 else -x[1])) # Right-endpoint first, tiebreaker with left-endpoint first
        res = [False] * len(queries)

        freqs = {}
        oddFreqs = set()

        def add(i):
            nonlocal freqs, oddFreqs
            if nums[i] in freqs:
                freqs[nums[i]] += 1
            else:
                freqs[nums[i]] = 1

            if nums[i] in oddFreqs:
                oddFreqs.remove(nums[i])
            else:
                oddFreqs.add(nums[i])

        def remove(i):
            nonlocal freqs, oddFreqs
            
            freqs[nums[i]] -= 1
            if freqs[nums[i]] == 0:
                del freqs[nums[i]]

            if nums[i] in oddFreqs:
                oddFreqs.remove(nums[i])
            else:
                oddFreqs.add(nums[i])

        res = [False] * q
        l, r = 0, -1
        
        for start, end, i in queries:
            while l > start:
                l -= 1
                add(l)
            while r < end:
                r += 1
                add(r)

            while l < start:
                remove(l)
                l += 1
            while r > end:
                remove(r)
                r -= 1

            res[i] = (len(freqs) == k and len(oddFreqs) == 0)

        return res