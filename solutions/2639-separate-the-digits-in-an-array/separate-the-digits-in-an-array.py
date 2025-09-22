class Solution:
    def separateDigits(self, nums: list[int]) -> list[int]:
        answer = []
        for num in nums:
            num = str(num)
            for char in num:
                answer.append(int(char))
        return answer