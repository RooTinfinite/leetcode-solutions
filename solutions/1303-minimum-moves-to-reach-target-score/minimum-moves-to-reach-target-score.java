class Solution {
    public int minMoves(int target, int maxDoubles) {
        // Count of moves needed to go from target to 1
        int moves = 0;
        
        // Work backwards: from target down to 1
        // Use double operations (halving in reverse) as long as we have them
        while (target > 1 && maxDoubles > 0) {
            if (target % 2 == 0) {
                // If target is even, it could have been reached by doubling target/2
                target /= 2;      // halve the number (reverse of double)
                maxDoubles--;     // consume one double operation
            } else {
                // If target is odd, it must have been reached by incrementing an even number
                target -= 1;      // decrement to make it even
            }
            moves++; // each operation (halve or decrement) counts as one move
        }
        
        // If we have no doubles left, we can only decrement until we reach 1
        // target - 1 is the number of decrements needed
        moves += target - 1;
        
        return moves;
    }
}