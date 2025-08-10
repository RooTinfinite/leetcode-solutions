class Solution:
    def checkMove(self, board: List[List[str]], rMove: int, cMove: int, color: str) -> bool:
        for di, dj in (0, 1), (1, 1), (1, 0), (1, -1), (0, -1), (-1, -1), (-1, 0), (-1, 1): 
            i, j = rMove+di, cMove+dj
            step = 0
            while 0 <= i < 8 and 0 <= j < 8: 
                if board[i][j] == color and step: return True 
                if board[i][j] == "." or board[i][j] == color and not step: break 
                i, j = i+di, j+dj
                step += 1
        return False