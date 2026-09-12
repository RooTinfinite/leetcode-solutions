class Solution:
    def maximumWeight(self, intervals: List[List[int]]) -> List[int]:
        n = len(intervals)
        arr = [
            (intervals[i][1], intervals[i][0], intervals[i][2], i)
            for i in range(n)
        ]
        # Sort by right endpoint.
        arr.sort(key=lambda x: x[0])

        dp = [[0] * 5 for _ in range(n + 1)]
        indices = [[[] for _ in range(5)] for _ in range(n + 1)]

        for i in range(n):
            r, l, weight, idx = arr[i]
            # Use binary search to find intervals whose right endpoints are smaller than l.
            k = bisect_left(arr, (l,), hi=i)

            for j in range(1, 5):
                s1 = dp[i][j]
                s2 = dp[k][j - 1] + weight
                if s1 > s2:
                    dp[i + 1][j] = dp[i][j]
                    indices[i + 1][j] = indices[i][j].copy()
                    continue

                new_index = indices[k][j - 1].copy()
                new_index.append(idx)
                new_index.sort()
                if s1 == s2 and indices[i][j] < new_index:
                    new_index = indices[i][j].copy()
                dp[i + 1][j] = s2
                indices[i + 1][j] = new_index

        return indices[n][4]