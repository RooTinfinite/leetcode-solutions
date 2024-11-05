class Solution:
    def maxOperations(self, nums: List[int], k: int) -> int:
        if len(nums) < 2:
            return 0
        counts = {}
        for num in nums:
            counts[num] = counts.get(num, 0) + 1
        ops = 0
        if k / 2 in counts:
            ops = counts[k/2] // 2
            del counts[k/2]
        for num, count in counts.items():
            if num >= k or count == 0: continue
            if k - num in counts:
                ops += min(count, counts[k - num])
                counts[k - num] = 0
        return ops

with open("user.out", "w") as f:
    inputs = map(loads, stdin)
    for nums in inputs:
        k = next(inputs)
        print(Solution().maxOperations(nums,k),file=f)
exit(0)