class Solution:
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        X, O = self.countBoard(board)
        if X - O not in {0, 1}:
            return False
        
        if self.checkBoard(board, 'X') and X == O:
            return False
        if self.checkBoard(board, 'O') and X - 1 == O:
            return False
        
        return True
        
    def checkBoard(self, board, player):
        for i in range(3):
            if board[i] == player * 3:
                return True
            if all(board[j][i] == player for j in range(3)):
                return True
        
        if player == board[1][1] == board[0][0] == board[2][2]:
            return True
        if player == board[1][1] == board[0][2] == board[2][0]:
            return True
            
    
    def countBoard(self, board):
        X, O = 0, 0
        for row in board:
            X += row.count('X')
            O += row.count('O')
        return X, O
        
        
        
    