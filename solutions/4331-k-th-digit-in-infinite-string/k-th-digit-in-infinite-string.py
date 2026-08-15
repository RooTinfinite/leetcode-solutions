class Solution:
    def kthDigit(self,k:int)->int:
        if k<=9:
            return k
        v=[0]
        p=1
        total=0
        for i in range(1,17):
            total+=9*p*i # digits contributed by all i-digit numbers
            v.append(total)
            p*=10
        v.append(total)
        idx=0
        for i in range(len(v)):
            if v[i]>=k:
                idx=i # target lies in the idx-digit group
                break
        k-=v[idx-1] # remove previous digit groups
        k-=1 # convert to 0-based indexing
        num=k//idx
        d=k%idx
        b=1
        for _ in range(idx-1):
            b*=10 # first idx-digit number
        val=b+num
        bb=val//10 # block number
        if bb%2:
            val=bb*10+(9-(val%10)) # odd blocks are reversed
        res=str(val)
        return int(res[d]) # return required digit