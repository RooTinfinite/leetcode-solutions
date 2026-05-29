class Solution:
    def confusingNumber(self, n: int) -> bool:
        tmp = {'0': 0, '1': 1, '6': 9, '8': 8, '9': 6}
        res = 0

        for i in str(n)[::-1]:
            if tmp.get(i) is None:
                return False
            else:
                res = (res * 10) + tmp[i]
            
        return res != n