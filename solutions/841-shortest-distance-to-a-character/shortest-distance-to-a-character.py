class Solution:
    def shortestToChar(self, s: str, c: str) -> List[int]:
        c1 = p = s.index(c)
        l = []
        for i in range(len(s)):
            if s[i]!=c:
                l.append(min(abs(c1-i),abs(p-i)))
            else:
                l.append(0)
                if i!=len(s)-1:
                    p = c1
                    print(i)
                    try:
                        c1 = s.index(c,i+1)
                    except:
                        c1 = p
        return l

        