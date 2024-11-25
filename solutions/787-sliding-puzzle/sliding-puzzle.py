class Solution:
    def slidingPuzzle(self, board: List[List[int]]) -> int:
        rows, cols = 2, 3
        nums = []
        curr, target = '', '123450'
        
        for i in range(rows):
            for j in range(cols):
                if board[i][j] != 0:
                    nums.append(board[i][j])
                curr += str(board[i][j])
        
        def isValid(nums):
            size = len(nums)
            inversions = sum(nums[i] > nums[j] for i in range(size) for j in range(i, size))
            return inversions % 2 == 0
        
        def heuristic(state):
            cost = 0
            for i in range(rows * cols):
                if state[i] != '0':
                    val = ord(state[i]) - ord('1')
                    cost += abs(i // cols - val // cols) + abs(i % cols - val % cols)
            return cost
        
        if not isValid(nums):
            return -1
            
        queue = [(heuristic(curr), curr)]
        moves = {curr: 0}
        
        while queue:
            _, state = heappop(queue)
            if state == target:
                return moves[state]
                
            pos = state.index('0')
            row, col = pos // cols, pos % cols
            chars = list(state)
            
            for dx, dy in [[0, -1], [0, 1], [1, 0], [-1, 0]]:
                newRow, newCol = row + dx, col + dy
                if 0 <= newRow < rows and 0 <= newCol < cols:
                    newPos = newRow * cols + newCol
                    chars[pos], chars[newPos] = chars[newPos], chars[pos]
                    nextState = ''.join(chars)
                    chars[pos], chars[newPos] = chars[newPos], chars[pos]
                    
                    if nextState not in moves or moves[nextState] > moves[state] + 1:
                        moves[nextState] = moves[state] + 1
                        heappush(queue, (moves[nextState] + heuristic(nextState), nextState))
        
        return -1
