class Cell:
    def __init__(self, val=0):
        self.val = val
        self.dependencies = []
        self.formula = None # this can be SUM, AVG etc, ony SUM for now

class Excel:

    def __init__(self, height: int, width: str):
        self.rows = height
        self.cols = ord(width) - ord('A') + 1
        self.cells = [[Cell() for _ in range(self.cols)] for _ in range(self.rows)]
        self.graph = defaultdict(set) # DAG between cells

    def _convert(self, row: int, column: str):
        return (row - 1, ord(column) - ord('A'))

    def _topological_sort(self, start_row, start_col):
        # Use Khan's algorithm
        # Collect all affected cells, and calculate in-degree
        s = [(start_row, start_col)]
        seen = {(start_row, start_col)}
        indegree = defaultdict(int)

        while s:
            cur_row, cur_col = s.pop()

            for nr, nc in self.graph[(cur_row, cur_col)]:
                indegree[(nr, nc)] += 1
                
                if (nr, nc) not in seen:
                    seen.add((nr, nc))
                    s.append((nr, nc))
        
        # Topological sort
        res = []
        q = deque([(start_row, start_col)])

        while q:
            cur_row, cur_col = q.popleft()

            for nr, nc in self.graph[(cur_row, cur_col)]:
                indegree[(nr, nc)] -= 1
                if indegree[(nr, nc)] == 0:
                    q.append((nr, nc))
                    res.append((nr, nc))
        
        return res
    
    def _recalculate(self, row, col):
        cell = self.cells[row][col]

        cell.val = 0
        for r, c in cell.dependencies:
            cell.val += self.cells[r][c].val
    
    def _update_dependent_cells(self, row, col):
        # Update all cells that depend on this cell. Need to topologically sort all cells
        for r, c in self._topological_sort(row, col):
            # recalculate value
            self._recalculate(r, c)
    
    def _update_graph_after_removing_formula(self, row, col):
        cell = self.cells[row][col]
        if len(cell.dependencies) > 0:
            for r, c in cell.dependencies:
                if (r, c) in self.graph and (row, col) in self.graph[(r, c)]:
                    self.graph[(r, c)].remove((row, col))

    def set(self, row: int, column: str, val: int) -> None:
        row, col = self._convert(row, column)
        self._update_graph_after_removing_formula(row, col)
        
        # Re-create the cell
        self.cells[row][col] = Cell(val)
        self._update_dependent_cells(row, col)

    def get(self, row: int, column: str) -> int:
        row, col = self._convert(row, column)
        return self.cells[row][col].val

    def sum(self, row: int, column: str, numbers: List[str]) -> int:
        row, col = self._convert(row, column)
        self._update_graph_after_removing_formula(row, col)

        # Re-create the cell
        cell = Cell()
        self.cells[row][col] = cell
        
        # Collect dependencies and update the graph
        for s in numbers:
            if ":" in s:
                # s is a range
                start, end = s.split(":")
                start_row, start_col = self._convert(int(start[1:]), start[0])
                end_row, end_col = self._convert(int(end[1:]), end[0])

                for r in range(start_row, end_row + 1):
                    for c in range(start_col, end_col + 1):
                        cell.dependencies.append((r, c))
                        self.graph[(r, c)].add((row, col))
            else:
                r, c = self._convert(int(s[1:]), s[0])
                cell.dependencies.append((r, c))
                self.graph[(r, c)].add((row, col))
        
        self._recalculate(row, col)
        self._update_dependent_cells(row, col)
        return cell.val


        


# Your Excel object will be instantiated and called as such:
# obj = Excel(height, width)
# obj.set(row,column,val)
# param_2 = obj.get(row,column)
# param_3 = obj.sum(row,column,numbers)