class Solution:
    def minimumTime(self, d: List[int], r: List[int]) -> int:
        def finish(t):
            a=t-t//r[0]
            b=t-t//r[1]
            total=t-t//(r[0]*r[1]//gcd(r[0],r[1]))
            return a>=d[0] and b>=d[1] and (d[0]+d[1])<=total
        l=0
        h=10**18
        while l<h:
            mid=(l+h)//2
            if finish(mid):
                h=mid
            else:
                l=mid+1
        return l
            
            
        
        
        
        