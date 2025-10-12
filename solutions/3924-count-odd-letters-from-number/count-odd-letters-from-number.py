class Solution:
    def countOddLetters(self, n: int) -> int:

        ord = [16577, 97, 4672, 648, 1218, 2067, 8464, 2336, 541, 17]
        toggle = 0

        while n:
            n, digit = divmod(n, 10)
            toggle^= ord[digit]

        return toggle.bit_count()    