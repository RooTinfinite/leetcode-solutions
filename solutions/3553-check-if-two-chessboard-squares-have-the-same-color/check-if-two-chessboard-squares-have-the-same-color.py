class Solution:
    def checkTwoChessboards(self, coordinate1: str, coordinate2: str) -> bool:
        val1 = (ord(coordinate1[0]) - ord('a') + 1 + int(coordinate1[1]))
        val2 = (ord(coordinate2[0]) - ord('a') + 1 + int(coordinate2[1]))
        return (val1 % 2) == (val2 % 2)