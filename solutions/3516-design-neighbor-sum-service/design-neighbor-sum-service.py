class NeighborSum:

    def __init__(self, grid: List[List[int]]):
        value_coord = {}
        coord_value = {}

        for row in range(len(grid)):
            for col in range(len(grid)):
                value_coord[grid[row][col]] = (row, col)
                coord_value[(row, col)] = grid[row][col]

        self.value_coord = value_coord
        self.coord_value = coord_value

    def adjacentSum(self, value: int) -> int:
        row, col = self.value_coord[value]

        sum = 0

        sum += self.coord_value[(row+1, col)] if (row+1, col) in self.coord_value else 0 # above
        sum += self.coord_value[(row-1, col)] if (row-1, col) in self.coord_value else 0 # below
        sum += self.coord_value[(row, col-1)] if (row, col-1) in self.coord_value else 0 # to the left
        sum += self.coord_value[(row, col+1)] if (row, col+1) in self.coord_value else 0 # to the right

        return sum

    def diagonalSum(self, value: int) -> int:
        row, col = self.value_coord[value]

        sum = 0

        sum += self.coord_value[(row-1, col-1)] if (row-1, col-1) in self.coord_value else 0 # up-left
        sum += self.coord_value[(row-1, col+1)] if (row-1, col+1) in self.coord_value else 0 # up-right
        sum += self.coord_value[(row+1, col-1)] if (row+1, col-1) in self.coord_value else 0 # down-left
        sum += self.coord_value[(row+1, col+1)] if (row+1, col+1) in self.coord_value else 0 # down-right

        return sum

# Your NeighborSum object will be instantiated and called as such:
# obj = NeighborSum(grid)
# param_1 = obj.adjacentSum(value)
# param_2 = obj.diagonalSum(value)