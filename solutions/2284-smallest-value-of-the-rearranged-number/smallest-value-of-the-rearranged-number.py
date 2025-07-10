class Solution:
    def smallestNumber(self, num: int) -> int:
        if num == 0:
            return 0
        elif num < 0:
            num = -num
            num = sorted(str(num), reverse = True)
            num = int(''.join(num))
            return -num
        else:
            num = str(num)
            count = num.count('0')
            num = sorted(num)
            num = num[count:count+1] + ['0']*count + num[count+1:]
            num = int(''.join(num))
            return num