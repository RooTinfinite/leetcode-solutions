class Solution:
    def maxWeight(self, weights: List[int], w1: int, w2: int) -> int:

        rows, cols = w1 + 2, w2 + 1

        nxt = cur = [[False]*(cols) for _ in range(rows)] 
        cur[0][0] = True
        
        for wgt in weights:
            cur, nxt = [tuple(row) for row in nxt], cur

            for tot1 in range(rows):
                for tot2 in range(cols):

                    if cur[tot1][tot2]:
                        if wgt <= w1 - tot1: 
                            nxt[tot1+wgt][tot2] = True
                        if wgt <= w2 - tot2: 
                            nxt[tot1][tot2+wgt] = True

            cur = nxt
            
        return max(tot1 + tot2 for tot1 in range(rows) 
                         for tot2 in range(cols) if cur[tot1][tot2])