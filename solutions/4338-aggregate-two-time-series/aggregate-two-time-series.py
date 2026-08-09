class Solution:
    def aggregateTimeSeries(self, series1: List[List[int]], series2: List[List[int]]) -> List[List[int]]:
        ans = []

        n1, n2 = len(series1), len(series2)
        i = j = 0

        while i < n1 or j < n2:
            if i == n1:
                t = series2[j][0]
            elif j == n2:
                t = series1[i][0]
            else:
                t = min(series1[i][0], series2[j][0])

            x1 = 0
            if i < n1:
                x1 = series1[i][1]

            x2 = 0
            if j < n2:
                x2 = series2[j][1]

            ans.append([t, x1 + x2])

            if i < n1 and series1[i][0] == t:
                i += 1

            if j < n2 and series2[j][0] == t:
                j += 1

        return ans