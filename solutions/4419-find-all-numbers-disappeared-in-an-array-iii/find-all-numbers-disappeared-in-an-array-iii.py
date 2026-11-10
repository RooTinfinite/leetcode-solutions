class Solution:
    def findDisappearedNumbers(self, nums: list[int], lower: int, upper: int) -> list[list[int]]:
        ans = []
        nums.sort()
        start = lower
        end = upper
        for num in nums:
            if num < start: continue
            curr_end = num-1
            curr_end = min(curr_end,upper)
            if curr_end>=start:
                ans.append([start,curr_end])
            start = max(start,num+1) #always needs reset
        if start <= upper:
            ans.append([start,upper])
        return ans


        