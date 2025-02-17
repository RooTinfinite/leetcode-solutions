class Solution:
    def maxAbsValExpr(self, arr1: List[int], arr2: List[int]) -> int:
        ppm=ppp=pmm=pmp=arr1[0]+arr2[0]
        mpm=mpp=mmm=mmp=arr1[0]-arr2[0]
        for i in range(1,len(arr1)):
            p=arr1[i]+arr2[i]
            m=arr1[i]-arr2[i]
            pp,pm,mp,mm=p+i,p-i,m+i,m-i
            if pp<ppm:
                ppm=pp
            elif pp>ppp:
                ppp=pp
            if pm<pmm:
                pmm=pm
            elif pm>pmp:
                pmp=pm
            if mp<mpm:
                mpm=mp
            elif mp>mpp:
                mpp=mp
            if mm<mmm:
                mmm=mm
            elif mm>mmp:
                mmp=mm
        return max(ppp-ppm,pmp-pmm,mpp-mpm,mmp-mmm)
        
        