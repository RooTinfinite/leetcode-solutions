class Solution:
    def minDays(self, bloomDay: List[int], m: int, k: int) -> int:
        n = len(bloomDay)
        
        # 1. Initial Feasibility Check
        if m * k > n:
            return -1
        
        def can_make_bouquets(days):
            """Checks if m bouquets can be made by the given 'days'."""
            bouquets = 0
            consecutive_count = 0
            
            for bloom_time in bloomDay:
                if bloom_time <= days:
                    # Flower has bloomed, continue the adjacent sequence
                    consecutive_count += 1
                else:
                    # Sequence broken
                    consecutive_count = 0
                
                # Check if we can form a bouquet
                if consecutive_count == k:
                    bouquets += 1
                    consecutive_count = 0 # Start counting a new sequence
            
            return bouquets >= m

        # 2. Determine Search Bounds
        L, R = min(bloomDay), max(bloomDay)
        min_days = -1
        
        # 3. Binary Search
        while L <= R:
            mid = L + (R - L) // 2
            
            if can_make_bouquets(mid):
                min_days = mid
                R = mid - 1  # Try for an earlier day
            else:
                L = mid + 1  # Need to wait longer
                
        return min_days