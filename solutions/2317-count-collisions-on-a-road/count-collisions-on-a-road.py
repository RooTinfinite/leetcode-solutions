class Solution(object):
    def countCollisions(self, directions):
        n = len(directions)
        left, right = 0, n - 1
        stationCount = 0
        if n == 1:
            return 0
        while left < n and directions[left] == "L":
            left += 1
        while right > 0 and directions[right] == "R":
            right -= 1
        for i in range(left, right + 1):
            car = directions[i]
            if car == "S":
                stationCount += 1                

        return right + 1 - left - stationCount