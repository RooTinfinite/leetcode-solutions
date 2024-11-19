class Solution:
    def countWinningSequences(self, s: str) -> int:
        n=len(s)
        MOD=10**9+7
        def get(alice,bob):
            if alice=='F' and bob=='E':
                return -1
            if alice=='F' and bob=='W':
                return 1
            if alice=='W' and bob=='F':
                return -1
            if alice=='W' and bob=='E':
                return 1
            if alice=='E' and bob=='F':
                return 1
            if alice=='E' and bob=='W':
                return -1
            return 0
        dp={}
        def func(prev,i,score):
            if(score+(n-i)<=0):
                return 0
            if(i==n):
                return 1
            if((prev,i,score) in dp):
                return dp[(prev,i,score)]
            points=0
            for x in "EFW":
                if(x!=prev):
                    d=get(s[i],x)
                    points+=func(x,i+1,score+d)
            dp[(prev,i,score)]=points % MOD
            return dp[(prev,i,score)]
        return func('',0,0) % MOD