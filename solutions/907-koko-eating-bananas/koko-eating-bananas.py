class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        
        while left < right:
            mid = left + (right - left) // 2
            
            if self.canEatAll(piles, h, mid):
                right = mid
            else:
                left = mid + 1
                
        return left
    
    def canEatAll(self, piles: List[int], h: int, k: int) -> bool:
        hours = 0
        for pile in piles:
            hours += (pile + k - 1) // k
            if hours > h:
                return False
        return True