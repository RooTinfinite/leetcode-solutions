class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        # Helper function that implements backtracking algorithm
        def backtrack(r):
            # Base case: if we've placed queens in all rows successfully
            if r == n:
                # Create a deep copy of current board state
                copy = board[:]
                sol = []
                # Convert each row to string representation
                for c in copy:
                    sol.append("".join(c[:]))
                # Add valid solution to final answer list
                ans.append(sol)
                return

            # Try placing queen in each column of current row
            for c in range(n):
                # Skip if column is attacked by another queen:
                # - placedCol: same column
                # - placedPos: same positive diagonal (r + c)
                # - placedNeg: same negative diagonal (r - c)
                if c in placedCol or r + c in placedPos or r - c in placedNeg:
                    continue

                # Place queen and mark attacked positions
                board[r][c] = "Q"
                placedCol.add(c)
                placedPos.add(r + c)
                placedNeg.add(r - c)

                # Recursively try to place queens in next rows
                backtrack(r + 1)

                # Backtrack: remove queen and unmark attacked positions
                board[r][c] = "."
                placedCol.remove(c)
                placedPos.remove(r + c)
                placedNeg.remove(r - c)

        # Initialize empty chess board
        board = [["."] * n for _ in range(n)]
        
        # Sets to track attacked positions:
        placedCol = set()  # Columns with queens
        placedPos = set()  # Positive diagonals (r + c)
        placedNeg = set()  # Negative diagonals (r - c)
        ans = []  # Store all valid solutions
        
        # Start backtracking from row 0
        backtrack(0)
        return ans

