class Solution:
    def minimumMountainRemovals(self, nums: List[int]) -> int:
        N = len(nums)
        right = [0]*N 
        tails = [-float(inf)] 
        for i in range(N-1, -1, -1):
            n = nums[i]
            l = bisect_left(tails, n)
            if l < len(tails):
                tails[l] = n
            else:
                tails.append(n) 
            right[i] = l
        tails = [-float(inf)]
        ans = N
        for i, n in enumerate(nums):
            l = bisect_left(tails, n)
            r = right[i]
            if l > 1 and r > 1:
                ans = min(ans, N-(l+r-1))
            if l < len(tails):
                tails[l] = n
            else:
                tails.append(n)
        return ans

with open("user.out", "w") as f:
    inputs = map(loads, stdin)
    for nums in inputs:
        print(Solution().minimumMountainRemovals(nums),file=f)
exit(0)