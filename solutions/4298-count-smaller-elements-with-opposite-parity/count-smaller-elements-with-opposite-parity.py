class Solution:
    def countSmallerOppositeParity(self, A: list[int]) -> list[int]:
        N = len(A)
        ans = [0] * N

        odd = SortedList()
        even = SortedList()

        for i in range(N-1, -1, -1):
            cnt = 0
            if A[i] % 2 == 0:
                even.add(A[i])
                cnt = odd.bisect_left(A[i])
            else:
                odd.add(A[i])
                cnt = even.bisect_left(A[i])
            ans[i] = cnt
        
        return ans