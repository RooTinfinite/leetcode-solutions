class Solution:
    def sumGame(self, num: str) -> bool:
        s1 = sum([int(s) if s != '?' else 0 for s in num[:len(num)//2]])
        s2 = sum([int(s) if s != '?' else 0 for s in num[(len(num)//2):]])
        st = num[:int(len(num)/2)].count('?')
        nd = num[int(len(num)/2):].count('?')
        if '?' not in num:
            return not s1==s2
        if (num.count('?'))%2!=0:
            return True
            
        diff = s1-s2
        diff_q = nd-st

        return diff*2!=diff_q*9
                


            