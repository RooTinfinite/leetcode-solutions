class Solution:
    def isLongPressedName(self, name: str, typed: str) -> bool:
        i=0
        for j in range (len(typed)):
            if i<len(name) and typed[j]==name[i]:
                i+=1
            elif j==0 or typed[j]!= typed[j-1]:
                return False
        return i==len(name)