class Solution:
    def largestSubmatrix(self, matrix: List[List[int]]) -> int:
        m = len(matrix)
        n = len(matrix[0])
        prev_row = [0] * n
        ans = 0
        
        for row in range(m):
            curr_row = matrix[row][:]
            for col in range(n):
                if curr_row[col] != 0:
                    curr_row[col] += prev_row[col]

            sorted_row = sorted(curr_row, reverse=True)
            for i in range(n):
                ans = max(ans, sorted_row[i] * (i + 1))

            prev_row = curr_row

        return ans