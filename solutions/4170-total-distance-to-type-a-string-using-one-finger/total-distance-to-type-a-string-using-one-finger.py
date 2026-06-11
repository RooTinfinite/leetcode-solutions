keyboard = (('q','w','e','r','t','y','u','i','o','p'),
            ('a','s','d','f','g','h','j','k','l'),
            ('z','x','c','v','b','n','m'))

class Solution:
    def totalDistance(self, s: str) -> int:

        d, dist, prvR,prvC = dict(), 0, 1,0

        for r, row in enumerate(keyboard):
            for c, col in enumerate(row):
                d[col] = (r, c)

        for ch in s:
            r, c = d[ch]
            dist+= abs(r - prvR) + abs(c - prvC)
            prvR, prvC = r, c

        return dist