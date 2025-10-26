class Solution:
    def removeZeros(self, n: int) -> int:
        result = str(n).replace("0", "")
        return int(result)