class Solution:
    def minOperations(self, nums: List[int]) -> List[int]:
        result=[]

        def palindrome(i):
            b = bin(i)[2:]
            return b==b[::-1]


        for n in nums:
            steps=0
            if not palindrome(n) :
                while True:
                    steps+=1
                    if palindrome(n-steps) or palindrome(n+steps):
                        break

            result.append(steps)

        return result
            