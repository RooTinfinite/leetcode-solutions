class Solution:
    def wordPattern(self, pattern: str, s: str) -> bool:

        l = s.split(" ")

        if len(l)!=len(pattern):
            return False

        d ={}
        se=set()

        for i in range(len(pattern)):
            if pattern[i] in d:
                if d[pattern[i]]!=l[i]:
                    return False
            else:
                if l[i] not in se:
                    d[pattern[i]]=l[i]
                    se.add(l[i])
                else:
                    return False
        
        return True