class Solution:
    def appendCharacters(self, s: str, t: str) -> int:
        if t in s:
            return 0
        if s.find(t[0])==-1:
            return len(t)
        i=0
        for ch in s:
            if ch==t[i]:
                i+=1
        return len(t)-i