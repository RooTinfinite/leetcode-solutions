bases=[[],[],[2],[3],[2,2],[5],[2,3],[7],[2,2,2],[3,3]]
primes=(2,3,5,7)
class Solution:
    def smallestNumber(self, num: str, t: int) -> str:
        count=[0]*10
        for p in primes:
            while t%p==0:
                count[p]+=1
                t=t//p
        if t!=1: return "-1"
        res=[int(ch) for ch in num]
        def inc(v, added):
            for p in bases[v]: count[p]+=added
        def getn():
            n2,n3,n5,n7 = [max(count[p], 0) for p in primes]
            n = n3//2 + n5 + n7
            if n3%2==1:
                n,n2 = n+1,n2-1
            return n + (n2+2)//3
        last = len(res)
        for i,v in enumerate(res):
            if v==0:
                last=i
                break
            inc(v, -1)
        def fill(start):
            # print("filling", res, start, count)
            for i in range(start, len(res)):
                for j in range(1,10):
                    inc(j, -1)
                    if getn() <= len(res)-1-i: 
                        res[i] = j
                        break
                    inc(j, 1)
            return ''.join(str(v) for v in res)
        if getn() <= len(res) - last: return fill(last)
        for i in range(last-1,-1,-1):
            inc(res[i],1)
            for j in range(res[i]+1,10):
                inc(j,-1)
                if getn() <= len(res)-1-i: 
                    res[i]=j
                    return fill(i+1)
                inc(j,1)
        res.append(0)
        nx = getn()
        while len(res)<nx: res.append(0)
        return fill(0)


        