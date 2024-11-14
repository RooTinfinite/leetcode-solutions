class Solution:
    def _solve_with_bin_search_by_value(self, n: int, q: List[int]) -> int:
        q.sort(reverse=True)
        m = len(q)
        left, right = 1, q[0]
        res = right
        while left <= right:
            free_slots = n - m
            mid = (left + right) // 2
            i = 0
            while i < m and free_slots >= 0:
                slots = math.ceil(q[i] / mid) - 1
                if not slots:
                    break
                free_slots -= slots
                i += 1
            if free_slots < 0: #not enough slots
                left = mid + 1
            else:
                right = mid - 1
                res = mid
        
        return res
            

    def minimizedMaximum(self, n: int, quantities: List[int]) -> int:
        if n == len(quantities):
            return max(quantities)

        return self._solve_with_bin_search_by_value(n, quantities)