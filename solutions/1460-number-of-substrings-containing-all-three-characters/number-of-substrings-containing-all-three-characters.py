class Solution:
    def numberOfSubstrings(self, s: str) -> int:
        store = {'a':0,'b':0,'c':0}
        left = result = 0
        for right in range(len(s)):
            store[s[right]]+=1
            while store['a']>0 and store['b']>0 and store['c']>0:
                result += len(s)-right
                store[s[left]]-=1
                left+=1
        return result
            