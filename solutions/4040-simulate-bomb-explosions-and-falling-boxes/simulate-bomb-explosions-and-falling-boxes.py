class Solution:
    def finalGrid(self, grid: List[List[str]]) -> List[List[str]]:
        emptyStr = '-'
        bombStr = '*'
        boxStr = '#'
        rowCnt = len(grid)
        colCnt = len(grid[0])
        colCntM1 = colCnt - 1

        boxFound = False
        bombFound = False
        for row in grid:  
            if not boxFound and any(ch == boxStr  for ch in row):
                boxFound = True
                if bombFound:  break
            if not bombFound and any(ch == bombStr  for ch in row):
                bombFound = True
                if boxFound:  break
        
        if not boxFound:        
            return grid

        if not bombFound:
            staticCnts = [0] * colCnt
            for r, row in enumerate(grid):
                for c, ch in enumerate(row):
                    if ch == boxStr:
                        staticCnts[c] += 1
                        grid[r][c] = emptyStr
            for c in range(colCnt):
                for r in range(rowCnt - staticCnts[c], rowCnt):
                    grid[r][c] = boxStr
            return grid

        for row in grid:  row.append(emptyStr)
        grid.append([emptyStr] * (colCnt + 3))

        result = [[emptyStr] * colCnt  for _ in range(rowCnt)]
        lastBomb = [-1] * (colCnt + 1)
        exploding = []
        for r, row in enumerate(grid):
            for c, ch in enumerate(row):
                if ch == bombStr:
                    lastBomb[c] = r
                    result[r][c] = bombStr
                    if row[c - 1] == boxStr or row[c + 1] == boxStr or   \
                                grid[r - 1][c] == boxStr or grid[r + 1][c] == boxStr:
                        exploding.append((r, c))

        for r,c in exploding:
            rP1 = r + 1;   rM1 = r - 1
            cP1 = c + 1;   cM1 = c - 1
            if grid[rM1][cM1] == boxStr:  grid[rM1][cM1] = emptyStr
            if grid[rM1][c  ] == boxStr:  grid[rM1][c  ] = emptyStr
            if grid[rM1][cP1] == boxStr:  grid[rM1][cP1] = emptyStr
            if grid[r  ][cM1] == boxStr:  grid[r  ][cM1] = emptyStr
            if grid[r  ][cP1] == boxStr:  grid[r  ][cP1] = emptyStr
            if grid[rP1][cM1] == boxStr:  grid[rP1][cM1] = emptyStr
            if grid[rP1][c  ] == boxStr:  grid[rP1][c  ] = emptyStr
            if grid[rP1][cP1] == boxStr:  grid[rP1][cP1] = emptyStr

        lastExplodable = [max(lastBomb[c - 1], lastBomb[c], lastBomb[c + 1])  \
                    for c in range(colCnt)]

        for c in range(colCnt):
            staticBoxes = sum((grid[r][c] == boxStr)  \
                        for r in range(lastExplodable[c] + 1, rowCnt))

            topStaticR = rowCnt - staticBoxes
            if staticBoxes > 0 and topStaticR > 1 and   \
                        (topStaticR == lastBomb[c - 1] + 1 or   \
                         topStaticR == lastBomb[c + 1] + 1):
                left = c
                right = c
                if topStaticR == lastBomb[c - 1] + 1:  left = max(0, c - 2)
                if topStaticR == lastBomb[c + 1] + 1:  right = min(colCntM1, c + 2)
                explosion = False
                for cTst in range(left, right + 1):
                    for r in range(topStaticR - 2, -1, -1):
                        if grid[r][cTst] == boxStr:
                            explosion = True
                            break
                        if result[r][cTst] == bombStr or result[r][cTst - 1] == bombStr or   \
                                    result[r][cTst + 1] == bombStr:
                            break
                    if explosion:  break
                if explosion:  topStaticR += 1

            for r in range(topStaticR, rowCnt):
                result[r][c] = boxStr

        return result