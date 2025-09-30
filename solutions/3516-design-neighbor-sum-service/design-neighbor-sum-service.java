class NeighborSum {
    private Map<Integer, Pair> value_coord;
    private Map<Pair, Integer> coord_value;

    public NeighborSum(int[][] grid) {
        value_coord = new HashMap<>();
        coord_value = new HashMap<>();

        for (int row = 0; row < grid.length; row++) {
            for (int col = 0; col < grid[row].length; col++) {
                value_coord.put(grid[row][col], new Pair(row, col));
                coord_value.put(new Pair(row, col), grid[row][col]);
            }
        }
    }

    public int adjacentSum(int value) {
        Pair rc = value_coord.get(value);
        int row = rc.row;
        int col = rc.col;

        int sum = 0;
        sum += coord_value.getOrDefault(new Pair(row + 1, col), 0); // above
        sum += coord_value.getOrDefault(new Pair(row - 1, col), 0); // below
        sum += coord_value.getOrDefault(new Pair(row, col - 1), 0); // left
        sum += coord_value.getOrDefault(new Pair(row, col + 1), 0); // right

        return sum;
    }

    public int diagonalSum(int value) {
        Pair rc = value_coord.get(value);
        int row = rc.row;
        int col = rc.col;

        int sum = 0;
        sum += coord_value.getOrDefault(new Pair(row - 1, col - 1), 0); // up-left
        sum += coord_value.getOrDefault(new Pair(row - 1, col + 1), 0); // up-right
        sum += coord_value.getOrDefault(new Pair(row + 1, col - 1), 0); // down-left
        sum += coord_value.getOrDefault(new Pair(row + 1, col + 1), 0); // down-right

        return sum;
    }

    private static class Pair {
        int row, col;
        Pair(int row, int col) { this.row = row; this.col = col; }

        @Override
        public boolean equals(Object o) {
            if (this == o) return true;
            if (!(o instanceof Pair)) return false;
            Pair p = (Pair) o;
            return row == p.row && col == p.col;
        }

        @Override
        public int hashCode() {
            return Objects.hash(row, col);
        }
    }
}