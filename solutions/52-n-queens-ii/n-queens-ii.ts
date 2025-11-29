function totalNQueens(n: number): number {
    let size = n;
    function backtrack(
        row: number,
        diagonals: Set<number>,
        antiDiagonals: Set<number>,
        cols: Set<number>,
    ): number {
        if (row == size) {
            return 1;
        }
        let solutions = 0;
        for (let col = 0; col < size; col++) {
            let currDiagonal = row - col;
            let currAntiDiagonal = row + col;
            // If the queen is not placeable
            if (
                cols.has(col) ||
                diagonals.has(currDiagonal) ||
                antiDiagonals.has(currAntiDiagonal)
            ) {
                continue;
            }
            // "Add" the queen to the board
            cols.add(col);
            diagonals.add(currDiagonal);
            antiDiagonals.add(currAntiDiagonal);
            // Move on to the next row with the updated board state
            solutions += backtrack(row + 1, diagonals, antiDiagonals, cols);
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            cols.delete(col);
            diagonals.delete(currDiagonal);
            antiDiagonals.delete(currAntiDiagonal);
        }
        return solutions;
    }
    return backtrack(0, new Set(), new Set(), new Set());
}