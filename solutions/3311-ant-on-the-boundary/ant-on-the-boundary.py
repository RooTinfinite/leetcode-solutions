class Solution:
    def returnToBoundaryCount(self, v):
        s, c = 0, 0
        for i in v:
            s += i
            if s == 0:
                c += 1
        return c