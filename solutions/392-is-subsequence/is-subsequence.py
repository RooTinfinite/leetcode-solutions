class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=0
        j=0
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                i+=1
                j+=1
                print(i)
            else:
                j+=1
        if len(s)==i:
            return True
        else:
            return False
        