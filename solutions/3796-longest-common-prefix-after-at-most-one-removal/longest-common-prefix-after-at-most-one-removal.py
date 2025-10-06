'''
URL := https://leetcode.com/problems/longest-common-prefix-after-at-most-one-removal/description/
3460. Longest Common Prefix After at Most One Removal
'''
class Solution:
    def longestCommonPrefix(self, s: str, t: str) -> int:
        lcp = 0
        ptrS = 0
        ptrT = 0
        numMismatch = 0
        while(ptrS < len(s) and ptrT < len(t)):
            letS = s[ptrS]
            letT = t[ptrT]
            if(letS == letT):
                ptrS += 1
                ptrT += 1
            else:
                if(numMismatch == 0):
                    numMismatch += 1
                    ptrS += 1
                else:
                    break
        # Get last pointer : where ptrT is
        lcp = ptrT
        return lcp
        