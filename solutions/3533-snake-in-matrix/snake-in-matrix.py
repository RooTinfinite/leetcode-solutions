class Solution(object):
    def finalPositionOfSnake(self, n, commands):
        x = 0
        dir = [[0] * 110 for _ in range(110)]
        for i in range(n):
            for j in range(n):
                dir[i][j] = x
                x += 1

        i, j = 0, 0
        for com in commands:
            if com == "RIGHT":
                j += 1
            elif com == "DOWN":
                i += 1
            elif com == "LEFT":
                j -= 1
            elif com == "UP":
                i -= 1

        return dir[i][j]