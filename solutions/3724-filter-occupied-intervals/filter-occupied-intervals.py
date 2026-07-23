class Solution:
    def filterOccupiedIntervals(self, arr, freeStart, freeEnd):
        arr.sort()

        temp = []

        for s, e in arr:
            if not temp or temp[-1][1] + 1 < s:
                temp.append([s, e])
            else:
                temp[-1][1] = max(temp[-1][1], e)

        res = []

        for s, e in temp:
            if e < freeStart or s > freeEnd:
                res.append([s, e])
            else:
                if s < freeStart:
                    res.append([s, freeStart - 1])

                if e > freeEnd:
                    res.append([freeEnd + 1, e])

        return res