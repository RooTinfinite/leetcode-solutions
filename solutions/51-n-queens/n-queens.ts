// TypeScript

function solveNQueens(n: number): string[][] {
    // Initialize board with n rows of n dots
    const board: string[] = Array(n).fill('.'.repeat(n));
    // Store all valid solutions
    const result: string[][] = [];
    
    // Check if placing a queen at [row,col] is valid
    function isSafe(row: number, col: number): boolean {
        // Check all rows above in the same column
        for (let i = 0; i < row; i++) {
            if (board[i][col] === 'Q') return false;
        }
        
        // Check upper-left diagonal path
        for (let i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] === 'Q') return false;
        }
        
        // Check upper-right diagonal path
        for (let i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] === 'Q') return false;
        }
        
        // Position is safe if no conflicts found
        return true;
    }
    
    // Recursive backtracking function
    function backtrack(row: number): void {
        // Base case: valid solution found when all rows are filled
        if (row === n) {
            result.push([...board]); // Create deep copy of solution
            return;
        }
        
        // Try each column in current row
        for (let col = 0; col < n; col++) {
            if (isSafe(row, col)) {
                // Place queen at current position
                board[row] = board[row].substring(0, col) + 'Q' + board[row].substring(col + 1);
                // Move to next row
                backtrack(row + 1);
                // Remove queen (backtrack) to try next position
                board[row] = board[row].substring(0, col) + '.' + board[row].substring(col + 1);
            }
        }
    }
    
    // Start backtracking from first row
    backtrack(0);
    return result;
}