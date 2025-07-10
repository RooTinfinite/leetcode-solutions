class Solution:
    def countOperations(self, num1: int, num2: int) -> int:
        cnt = 0
        while num1 and num2:
            if num1 >= num2:
                cnt += num1 // num2
                num1 %= num2
            else:
                cnt += num2 // num1
                num2 %= num1
        return cnt