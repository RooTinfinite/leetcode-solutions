class Solution:
    def generateTheString(self, n: int) -> str:
        return "e"+ (n-1)*"z" if n%2 == 0 else n*"z"