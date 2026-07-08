class Solution:
    def countDigitOccurrences(self, nums: list[int], digit: int) -> int:
        sum=0
        for i in nums:
            i=str(i)
            a=list(i)

            for j in a:

                if str(digit)==j:
                    sum+=1
        return sum





