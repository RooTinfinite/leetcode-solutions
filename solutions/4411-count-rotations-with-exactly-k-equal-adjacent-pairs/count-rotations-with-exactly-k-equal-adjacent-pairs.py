class Solution:
    def countRotations(self, s: str, k: int) -> int:
        '''In contests'''
        n=len(s)
        count=0
        for i in range(n):
            t=s[i:]+s[:i]
            sumL=0
            for j in range(n-1):
                if t[j]==t[j+1]:
                    sumL+=1
            if sumL==k:
                count+=1
        return count




        '''O(n) , O(n)'''
        n=len(s)
        s+=s
        sumL=0
        for i in range(n-1):
            if s[i]==s[i+1]:
                sumL+=1
        count=0
        for i in range(n):
            if sumL==k:
                count+=1
            if s[i]==s[i+1]:
                sumL-=1
            if s[i+n-1]==s[(i+1)+(n-1)]:
                sumL+=1
        return count



        '''O(n) , O(1)'''
        n=len(s)
        sumL=0
        for i in range(n-1):
            if s[i]==s[i+1]:
                sumL+=1
        count=0
        for i in range(n):
            if sumL==k:
                count+=1
            if s[i]==s[(i+1)%n]:
                sumL-=1
            if s[(i+n-1)%n]==s[((i+1)+(n-1))%n]:
                sumL+=1
        return count 