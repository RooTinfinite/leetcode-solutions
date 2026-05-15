class Solution {

    private static final int[] DIRECTIONS = { 0, 1, 0, -1, 0 };

    public int numberOfCleanRooms(int[][] room) {
        int rows = room.length;
        int cols = room[0].length;
        int cleaned = 0;

        int row = 0, col = 0;
        int direction = 0;

        // Clean until we revisit a space facing the same direction
        while (((room[row][col] >> (direction + 1)) & 1) == 0) {
            // If the robot hasn't cleaned this space yet, increment cleaned
            if (room[row][col] == 0) {
                cleaned += 1;
            }

            // Mark the space as visited facing this direction
            room[row][col] |= 1 << (direction + 1);

            // Clean the next space straight ahead if it's empty and in the room
            int nextRow = row + DIRECTIONS[direction];
            int nextCol = col + DIRECTIONS[direction + 1];
            if (
                0 <= nextRow &&
                nextRow < rows &&
                0 <= nextCol &&
                nextCol < cols &&
                room[nextRow][nextCol] != 1
            ) {
                row = nextRow;
                col = nextCol;
            } else {
                // Otherwise turn right and clean the current space
                direction = (direction + 1) % 4;
            }
        }
        return cleaned;
    }
}