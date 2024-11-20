class Solution:
    def addDigits(self, num: int) -> int:
        while num > 9:
            current_sum = 0
            while num:
                current_sum += num % 10
                num //= 10
            num = current_sum
        return num