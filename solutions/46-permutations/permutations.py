class Solution:
    def solve(self, nums: list[int], l: int, r: int, result: list[list[int]]) -> None:
        # Base case: when left index equals right index
        if l == r:
            result.append(nums[:])  # Add copy of current permutation
            return
        
        # Try all possible elements at position 'l'
        for i in range(l, r + 1):
            # 1. Swap current element with element at position 'l'
            nums[l], nums[i] = nums[i], nums[l]
            
            # 2. Recursively generate permutations for remaining elements
            self.solve(nums, l + 1, r, result)
            
            # 3. Backtrack: restore array to original state by swapping back
            nums[l], nums[i] = nums[i], nums[l]
    
    def permute(self, nums: list[int]) -> list[list[int]]:
        result = []  # Stores all permutations
        self.solve(nums, 0, len(nums) - 1, result)  # Start with full array range
        return result