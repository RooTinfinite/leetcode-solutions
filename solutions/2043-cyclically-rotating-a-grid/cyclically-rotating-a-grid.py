class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
  
        m, n = len(grid), len(grid[0])
        MN = min(m, n)//2
 
        for i in range(MN):

            XO, X1, YO, Y1 = i, m-i-1, i, n-i-1
            rot  = k%(2*(X1+Y1-XO-YO))      

            layerXY = list(chain( [(XO, y) for y in range(YO,  Y1)],
                                  [(x, Y1) for x in range(XO,  X1)],
                                  [(X1, y) for y in range(YO+1,Y1+1)][::-1],
                                  [(x, YO) for x in range(XO+1,X1+1)][::-1]))

            layer = [grid[a][b] for (a,b) in layerXY]
            layer = zip(layer[rot:]+layer[:rot], layerXY)

            for num, (a,b) in layer: grid[a][b] = num

        return grid