class Solution:
    def minTotalTime(self, forward: List[int], backward: List[int], queries: List[int]) -> int:
        n = len(forward)
        fwd = [0] * (n + 1)
        bwd = [0] * (n + 1)
        for i in range(1, n + 1):
            fwd[i] = fwd[i-1] + forward[i-1]
            bwd[i] = bwd[i-1] + (backward[i] if i < n else backward[0])
        res, cur = 0, 0
        for q in queries:
            u, v = cur, q
            # clockwise distance from u to v
            if u <= v:  cw = fwd[v] - fwd[u]
            else:       cw = fwd[n] - (fwd[u] - fwd[v])
            # counter-clockwise distance from u to v
            if u >= v:  ccw = bwd[u] - bwd[v]
            else:       ccw = bwd[n] - (bwd[v] - bwd[u])
            res += min(cw, ccw)
            cur = v
        return res