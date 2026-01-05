class Solution:
    def maxMatrixSum(self, matrix: List[List[int]]) -> int:
        flat = [abs(num) for row in matrix for num in row]
        neg_count = sum(1 for row in matrix for num in row if num < 0)
        total = sum(flat)
        min_val = min(flat)
        return total if neg_count % 2 == 0 else total - 2 * min_val