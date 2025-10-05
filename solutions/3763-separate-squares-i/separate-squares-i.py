class Solution:
    def separateSquares(self, squares: List[List[int]]) -> float:
        def helper(line: float, squares: List[List[int]]) -> float:
            aAbove = 0.0
            aBelow = 0.0
            for sq in squares:
                x, y, l = sq
                total = l * l
                if line <= y:
                    aAbove += total
                elif line >= y + l:
                    aBelow += total
                else:
                    # The line intersects the square.
                    aboveHeight = (y + l) - line
                    belowHeight = line - y
                    aAbove += l * aboveHeight
                    aBelow += l * belowHeight
            return aAbove - aBelow

        lo = 0
        hi = 2*1e9
        
        for _ in range(60):
            mid = (lo + hi) / 2.0
            diff = helper(mid, squares)
            

            if diff > 0:
                lo = mid
            else:
                hi = mid
        
        return hi