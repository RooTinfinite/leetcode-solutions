class Solution:
    def passwordStrength(self, password: str) -> int:
        uppercase=[False]*26
        lowercase=[False]*26
        number=[False]*26
        splchar=[False]*26
        count=0
        for ch in password:
            if('a'<=ch<='z'):
                i=ord(ch)-ord('a')
                if not lowercase[i]:
                    lowercase[i]=True
                    count+=1
            elif('A'<=ch<='Z'):
                i=ord(ch)-ord('A')
                if not uppercase[i]:
                    uppercase[i]=True
                    count+=2
            elif('0'<=ch<='9'):
                i=ord(ch)-ord('0')
                if not number[i]:
                    number[i]=True
                    count+=3
            else:
                i="!@#$".index(ch)
                if not splchar[i]:
                    splchar[i]=True
                    count+=5
        return count
                    