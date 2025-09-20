class Solution:
    def palindrome(self,num):
        rev=0
        while num>0:
            digit=num%10
            rev=rev*10+digit
            num=num//10
        return rev
    def sumOfNumberAndReverse(self, num: int) -> bool:
        for i in range(num+1):
            if num==i+self.palindrome(i):
                return True
        return False

        