class Solution:
    def largestGoodInteger(self, num: str) -> str:
        return max((x*3 for x,y,z in zip(num, num[1:], num[2:]) if x==y==z), default='')
        