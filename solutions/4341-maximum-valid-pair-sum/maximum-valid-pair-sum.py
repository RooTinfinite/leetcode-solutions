class Solution:
    def maxValidPairSum(self, a: List[int], k: int) -> int:
        n=len(a)
        sf=[0]*(n+1)
        for i in range(n-1,-1,-1):
            sf[i]=max(a[i],sf[i+1]) # maximum value from i to end
        ans=0
        for i in range(n-k):
            ans=max(ans,a[i]+sf[i+k]) # best partner for index i
        return ans