class Solution:
    def countStableSubarrays(self, A: List[int], queries: List[List[int]]) -> List[int]:
        N = len(A)

        intervals = []
        anchor = 0
        for i in range(N):
            if i == N - 1 or A[i] > A[i + 1]:
                intervals.append([anchor, i])
                anchor = i + 1

        who = [0] * N
        for index, (l, r) in enumerate(intervals):
            for i in range(l, r + 1):
                who[i] = index
        
        P = [0]
        for l, r in intervals:
            w = r - l + 1
            cur = w * (w + 1) // 2
            P.append(P[-1] + cur)

        ans = []
        for l, r in queries:
            l_id, r_id = who[l], who[r]
            
            if l_id == r_id:
                w = r - l + 1
                ans.append(w * (w + 1) // 2)
                continue
            
            l1, r1 = intervals[l_id]
            l2, r2 = intervals[r_id]
            w_left = r1 - l + 1
            w_right = r - l2 + 1
            
            cur = P[r_id] - P[l_id + 1]
            cur += w_left * (w_left + 1) // 2
            cur += w_right * (w_right + 1) // 2
            ans.append(cur)

        return ans