class Solution:
    def findDegrees(self, matrix: list[list[int]]) -> list[int]:
        
       return list(map(sum, matrix))
       