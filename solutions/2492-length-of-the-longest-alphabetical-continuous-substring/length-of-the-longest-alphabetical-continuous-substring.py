class Solution:
    def longestContinuousSubstring(self, s: str) -> int:
        cur = 1 ### We are currently at 0 position, so the length is 1.
        res = 1 ### At least the string should contain 1 letter.
        for i in range(1,len(s)):
        	### If the ith letter is continued from the previous letter, 
        	### update the curLength and store the maximum length to res
            if ord(s[i])-ord(s[i-1])==1:
                cur = cur+1
                res = max(cur,res)
            ### This is the start of a new substring with length 1.
            else:
                cur = 1
        return res