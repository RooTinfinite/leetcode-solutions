class Solution:
    def findCombinations(self, index: int, target: int, candidates: List[int], current: List[int], result: List[List[int]]) -> None:
        # Base case: if target becomes 0, we found a valid combination
        if target == 0:
            result.append(current[:])  # Add a copy of current combination to result
            return
        
        # Try all possible numbers from current index
        for i in range(index, len(candidates)):
            # Only proceed if current number doesn't exceed target
            if candidates[i] <= target:
                # Include current number in combination
                current.append(candidates[i])
                
                # Recursive call with:
                # - same index i (allowing reuse of same number)
                # - reduced target by current number
                self.findCombinations(i, target - candidates[i], candidates, current, result)
                
                # Backtrack: remove the last added number to try other combinations
                current.pop()
    
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        result = []        # Stores all valid combinations
        current = []       # Temporary list to build combinations
        self.findCombinations(0, target, candidates, current, result)
        return result