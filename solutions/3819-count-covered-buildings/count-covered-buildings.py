class Solution:
    def countCoveredBuildings(self, n: int, buildings: List[List[int]]) -> int:
        yRangeGivenX = {}
        xRangeGivenY = {}

        for x, y in buildings:
            if x not in yRangeGivenX:
                yRangeGivenX[x] = [n + 1, 0]  # [minY, maxY]
            yRangeGivenX[x][0] = min(yRangeGivenX[x][0], y)
            yRangeGivenX[x][1] = max(yRangeGivenX[x][1], y)

            if y not in xRangeGivenY:
                xRangeGivenY[y] = [n + 1, 0]  # [minX, maxX]
            xRangeGivenY[y][0] = min(xRangeGivenY[y][0], x)
            xRangeGivenY[y][1] = max(xRangeGivenY[y][1], x)

        count = 0
        for x, y in buildings:
            minX, maxX = xRangeGivenY[y]
            minY, maxY = yRangeGivenX[x]
            if minX < x < maxX and minY < y < maxY:
                count += 1

        return count