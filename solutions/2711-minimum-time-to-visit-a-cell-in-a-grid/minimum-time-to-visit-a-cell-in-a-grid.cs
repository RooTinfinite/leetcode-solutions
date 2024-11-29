public class Solution
{
    int[][] grid;
    int[,] res;
    int rows, cols;
    PriorityQueue<(int, int), int> toExplore = new PriorityQueue<(int, int), int>();

    public int MinimumTime(int[][] grid)
    {
        if(grid[0][1] > 1 && grid[1][0] > 1)
            return -1;
        this.grid = grid;
        rows = grid.Length;
        cols = grid[0].Length;
        res = new int[rows, cols];

        for(int i = 0; i < rows; i++)
            for(int j = 0; j < cols; j++)
                res[i,j] = int.MaxValue;
        res[0,0] = 0;

        toExplore.Enqueue((0, 0), 0);
        while(toExplore.Count > 0)
        {
            var cell = toExplore.Dequeue();
            ExploreNeighbors(cell);
        }

        return res[rows-1, cols-1];
    }

    private void ExploreNeighbors((int row, int col) cell)
    {
        foreach(var neighbor in GetNeighbors(cell))
        {
            var newVal = MoveTo(cell, neighbor);
            if(newVal < res[neighbor.row, neighbor.col])
            {
                res[neighbor.row, neighbor.col] = newVal;
                toExplore.Enqueue(neighbor, newVal);
            }
        }
    }

    private int MoveTo((int row, int col) cell, (int row, int col) neighbor)
    {
        int step = res[cell.row, cell.col]+1;
        int minVal = grid[neighbor.row][neighbor.col];
        if(minVal <= step)
            return step;
        else if(AreSamePairity(minVal, step))
            return minVal;
        return minVal+1;
    }

    private IEnumerable<(int row, int col)> GetNeighbors((int row, int col) cell)
    {
        if(cell.col > 0) yield return (cell.row, cell.col-1);
        if(cell.row > 0) yield return (cell.row-1, cell.col);
        if(cell.col < cols-1) yield return (cell.row, cell.col+1);
        if(cell.row < rows-1) yield return (cell.row+1, cell.col);
    }

    private bool AreSamePairity(int x, int y) => x%2 == y%2;
}