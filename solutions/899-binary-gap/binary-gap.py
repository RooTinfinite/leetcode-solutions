class Solution:
    def binaryGap(self, n: int) -> int:
        flag = 0
        maxi = 0
        i = 0
        binary = bin(n)[2:]
        while i < len(binary):
            if binary[i] == "1":
                maxi = max(maxi,abs(i - flag))
                flag = i
            i += 1
        return maxi