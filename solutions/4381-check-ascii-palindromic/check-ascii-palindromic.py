class Solution:
    def isPalindromic(self, s: str) -> bool:
        binary = ""

        for c in s:
            ascii_val = ord(c)
            binary += format(ascii_val, '08b')

        i, j = 0, len(binary) - 1

        while i < j:
            if binary[i] != binary[j]:
                return False
            i += 1
            j -= 1

        return True