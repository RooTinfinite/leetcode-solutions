class Solution:
    def checkValid(self, matrix: List[List[int]]) -> bool:
        n=len(matrix)
        for row in matrix:
            if len(set(row))!=n: return False

        transposed=list(zip(*matrix))
        for column in transposed:
            if len(set(column))!=n: return False
        return True