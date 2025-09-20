class Solution:
    def largestPalindromic(self, num: str) -> str:
        c = Counter(num)
        if len(c)==1 and c['0']>=1:
            return "0"
        m = -1   #storing the mid of the number
        res1 = ''
        res2 = ''
        for i in range(9,-1,-1):
            while c[str(i)]:
                if not res1 and i==0:   #to avoid adding 0 at first
                    break 
                if c[str(i)]>=2:

                    res1 += str(i)
                    res2 = str(i) + res2
                    c[str(i)]-=2
                if c[str(i)] == 1:
                    m = max(m,i)  #updating medium to max
                    c[str(i)]-=1
                if c[str(i)]==0:
                    del c[str(i)]
        return res1+res2 if m==-1 else res1 + str(m) + res2