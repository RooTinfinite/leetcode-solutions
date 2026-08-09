class Solution:
    def rearrangeString(self, s: str, x: str, y: str) -> str:
        xc = []
        yc = []
        others = []
        
        for c in s:
            if c == y:
                yc.append(c)
            elif c == x:
                xc.append(c)
            else:
                others.append(c)
                
        return "".join(yc + others + xc)
