class Solution:
    def eliminateMaximum(self, dist: List[int], speed: List[int]) -> int:
        n = len(dist)
        monsters = [0] * n

        for i in range(n):
            arrival = math.ceil(dist[i] / speed[i])

            if arrival < n:
                monsters[arrival] += 1

        eliminated = 0
        for i in range(n):
            if eliminated + monsters[i] > i:
                return i

            eliminated += monsters[i]

        return n        