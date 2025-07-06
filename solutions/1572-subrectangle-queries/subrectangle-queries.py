class SubrectangleQueries:
    def __init__(self, rectangle):
        self.rect = rectangle

    def updateSubrectangle(self, row1, col1, row2, col2, newValue):
        for i in range(row1, row2 + 1):
            for j in range(col1, col2 + 1):
                self.rect[i][j] = newValue

    def getValue(self, row, col):
        return self.rect[row][col]