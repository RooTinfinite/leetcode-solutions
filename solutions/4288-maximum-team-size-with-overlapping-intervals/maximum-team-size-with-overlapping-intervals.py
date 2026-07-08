class Solution:
    def maximumTeamSize(self, startTime: list[int], 
                              endTime: list[int]) -> int:
        ans = 0
        empTimes = zip(startTime[::], endTime[::])
        
        startTime.sort()
        endTime.sort()

        for empBeg, empEnd in empTimes:
            lft = bisect_left (endTime  , empBeg)
            rgt = bisect_right(startTime, empEnd)
            ans = max(ans, rgt - lft)
           
        return ans
