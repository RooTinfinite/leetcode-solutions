func solveNQueens(n int) [][]string {
    solutions := make([][]string, 0)
    emptyBoard := make([][]rune, n)
    for i := range emptyBoard {
        emptyBoard[i] = make([]rune, n)
        for j := range emptyBoard[i] {
            emptyBoard[i][j] = '.'
        }
    }
    hasElement := func(set map[int]bool, value int) bool {
        _, ok := set[value]
        return ok
    }
    addElement := func(set map[int]bool, value int) {
        set[value] = true
    }
    removeElement := func(set map[int]bool, value int) {
        delete(set, value)
    }
    // Making use of a helper function to get the
    // solutions in the correct output format
    createBoard := func(state [][]rune) []string {
        board := make([]string, len(state))
        for row := range state {
            board[row] = string(state[row])
        }
        return board
    }
    var backtrack func(row int, diagonals, antiDiagonals, cols map[int]bool, state [][]rune)
    backtrack = func(row int, diagonals, antiDiagonals, cols map[int]bool, state [][]rune) {
        // Base case - N queens have been placed
        if row == n {
            solutions = append(solutions, createBoard(state))
            return
        }
        for col := 0; col < n; col++ {
            currDiagonal := row - col
            currAntiDiagonal := row + col
            // If the queen is not placeable
            if hasElement(cols, col) || hasElement(diagonals, currDiagonal) ||
                hasElement(antiDiagonals, currAntiDiagonal) {
                continue
            }
            // "Add" the queen to the board
            addElement(cols, col)
            addElement(diagonals, currDiagonal)
            addElement(antiDiagonals, currAntiDiagonal)
            state[row][col] = 'Q'
            // Move on to the next row with the updated board state
            backtrack(row+1, diagonals, antiDiagonals, cols, state)
            // "Remove" the queen from the board since we have already
            // explored all valid paths using the above function call
            removeElement(cols, col)
            removeElement(diagonals, currDiagonal)
            removeElement(antiDiagonals, currAntiDiagonal)
            state[row][col] = '.'
        }
    }
    backtrack(
        0,
        make(map[int]bool),
        make(map[int]bool),
        make(map[int]bool),
        emptyBoard,
    )
    return solutions
}