class Solution:
	"""
	Time:   O(n*m*log(max(n,m))
	Memory: O(n + m)
	"""

	def diagonalSort(self, matrix: List[List[int]]) -> List[List[int]]:
		n, m = len(matrix), len(matrix[0])
		diagonals = [(i, 0) for i in range(n - 1, 0, -1)] + [(0, j) for j in range(m)]

		for row, col in diagonals:
			for val in sorted(self._diagonal_generator(row, col, matrix)):
				matrix[row][col] = val
				row += 1
				col += 1

		return matrix

	@staticmethod
	def _diagonal_generator(r: int, c: int, matrix: List[List[int]]):
		while r < len(matrix) and c < len(matrix[0]):
			yield matrix[r][c]
			r += 1
			c += 1