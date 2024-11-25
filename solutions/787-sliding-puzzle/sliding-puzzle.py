from typing import List
from collections import deque

class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        # Directions map: key is the index of the blank space (0), and values are the indices it can swap with.
        dirs = {
            0: [1, 3], 
            1: [0, 2, 4], 
            2: [1, 5], 
            3: [0, 4], 
            4: [1, 3, 5], 
            5: [2, 4]
        }
        # Flatten the board to a single list and start the BFS queue with this initial state and move count of 0.
        state = list((*board[0], *board[1]))
        q = deque([(state, 0)])  # Queue for BFS, containing tuples of (current state, move count)
        visit = set()  # Set to keep track of visited states

        # Begin BFS
        while q:
            state, count = q.popleft()  # Current state and its move count
            # If the current state is the goal state, return the move count.
            if state == [1, 2, 3, 4, 5, 0]:
                return count

            idx = state.index(0)  # Find the index of the blank space (0)

            # Iterate over all possible directions the blank space can move
            for new_i in dirs[idx]:
                cur = state[:]  # Create a copy of the current state
                cur[idx], cur[new_i] = cur[new_i], 0  # Swap the blank space with the adjacent number
                
                # If we haven't visited this state before, add it to the queue and the visited set
                cur_tuple = tuple(cur)  # Convert list to tuple for hashability
                if cur_tuple not in visit:
                    visit.add(cur_tuple)
                    q.append((cur, count + 1))  # Add new state with incremented move count to the queue
        
        # If the loop ends without returning, the puzzle is unsolvable.
        return -1