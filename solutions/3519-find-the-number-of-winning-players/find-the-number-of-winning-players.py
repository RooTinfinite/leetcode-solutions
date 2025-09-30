class Solution:
    def winningPlayerCount(self, n: int, pick: List[List[int]]) -> int:
        res = 0
        seen = set()
        players = [[0] * 11 for _ in range(n)]
        for x, y in pick:
            if players[x][y] == x and x not in seen:
                res += 1
                seen.add(x)
            players[x][y] += 1
        return res