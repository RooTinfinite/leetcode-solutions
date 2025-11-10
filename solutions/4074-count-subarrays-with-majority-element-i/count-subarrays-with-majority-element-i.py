class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:

        n, ans = len(nums), 0
        pref = [0] * (n + 1)

        for i in range(n):
            if nums[i] == target:
                pref[i + 1] = pref[i] + 1
            else:
                pref[i + 1] = pref[i] - 1

        for i in range(n):
            left = pref[i]
            for j in range(i+1, n+1):
                if pref[j] > left : ans+= 1

        return ans