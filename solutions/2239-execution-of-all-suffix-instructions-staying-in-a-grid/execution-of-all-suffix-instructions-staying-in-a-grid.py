class Solution:
    def executeInstructions(self, n: int, startPos: list[int], s: str) -> list[int]:
        m = len(s)
        answer = [0]*m
        moves = {'L':(0,-1),'R':(0,1),'U':(-1,0),'D':(1,0)}
        for i in range(m):
            r, c = startPos
            cnt = 0
            for ch in s[i:]:
                dr, dc = moves[ch]
                r += dr
                c += dc
                if r < 0 or r >= n or c < 0 or c >= n:
                    break
                cnt += 1
            answer[i] = cnt
        return answer