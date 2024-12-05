class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if start==target:
            return True
        need_l=0
        store_r=0
        for s,v in zip(start, target):
            if s=='R':
                if need_l>0:
                    return False
                store_r+=1
            if v=='L':
                if store_r>0:
                    return False
                need_l+=1
            if v=='R':
                if store_r==0:
                    return False
                store_r-=1
            if s=="L":
                if need_l==0:
                    return False
                need_l-=1                    
        return need_l==0 and store_r==0