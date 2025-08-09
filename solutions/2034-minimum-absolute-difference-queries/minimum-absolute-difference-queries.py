class Solution:
    def minDifference(self, a: List[int], q: List[List[int]]) -> List[int]:
        p = [
            *accumulate(a,
                lambda p,v: [z+(v==i) for i,z in enumerate(p)],
                initial = [0]*(max(a)+1)
            )
        ]

        return [
            -max(
                starmap(
                    sub,
                    pairwise(i for i,z in enumerate(map(sub,p[r+1],p[l])) if z)
                ),
                default = 1
            )
                for l,r in q
        ]