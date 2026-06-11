class Solution {
    //map['x'] = x's position on the keyboard
    private static final int[][] map = {{1, 0}, {2, 4}, {2, 2}, {1, 2}, {0, 2}, {1, 3}, {1, 4}, {1, 5}, {0, 7}, {1, 6}, {1, 7}, {1, 8}, {2, 6}, {2, 5}, {0, 8}, {0, 9}, {0, 0}, {0, 3}, {1, 1}, {0, 4}, {0, 6}, {2, 3}, {0, 1}, {2, 1}, {0, 5}, {2, 0}};
    public int totalDistance(String s) {
        int prevRow = 1, prevCol = 0; //start at map['a']
        int ans = 0;

        for(char c : s.toCharArray()) {
            int row = map[c - 'a'][0], col = map[c - 'a'][1];

            ans += Math.abs(row - prevRow) + Math.abs(col - prevCol);

            prevRow = row;
            prevCol = col;
        }
        return ans;
    }
}