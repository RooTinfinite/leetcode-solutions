class Solution:
    def maxSatisfied(self, customers: List[int], grumpy: List[int], minutes: int) -> int:
        n = len(customers)
        base_satisfied = 0
        
        # 1. Calculate Guaranteed Satisfied Customers (Base)
        # We also identify the potential bonus customers we could save.
        potential_bonus = [0] * n
        for i in range(n):
            if grumpy[i] == 0:
                # Owner is NOT grumpy: customers are satisfied regardless of the technique.
                base_satisfied += customers[i]
            else:
                # Owner IS grumpy: these are the customers we can potentially save.
                potential_bonus[i] = customers[i]

        # Handle the edge case where the window size is the whole array
        if minutes >= n:
            return base_satisfied + sum(potential_bonus)

        # 2. Sliding Window to Find Maximum Bonus
        current_bonus = 0
        
        # Calculate sum for the initial window (0 to minutes - 1)
        for i in range(minutes):
            current_bonus += potential_bonus[i]
        
        max_bonus = current_bonus

        # Slide the window from index 'minutes' up to 'n - 1'
        for i in range(minutes, n):
            # Element leaving the window (at i - minutes)
            leaving_bonus = potential_bonus[i - minutes]
            
            # Element entering the window (at i)
            entering_bonus = potential_bonus[i]
            
            # Update current window sum in O(1)
            current_bonus = current_bonus - leaving_bonus + entering_bonus
            
            # Update the maximum bonus found so far
            max_bonus = max(max_bonus, current_bonus)

        # 3. Calculate Final Result
        return base_satisfied + max_bonus