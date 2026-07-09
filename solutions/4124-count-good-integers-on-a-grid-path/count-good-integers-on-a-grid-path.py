from functools import cache

class Solution:
    def countGoodIntegersOnPath(self, l: int, r: int, directions: str) -> int:
        indices = [0]
        row, col = 0, 0
        
        # Convert 'D' and 'R' directions into 1D grid indices
        for char in directions:
            if char == 'D':
                row += 1
            else:
                col += 1
            indices.append(4 * row + col)
            
        def get(limit: int) -> int:
            if limit < 0: 
                return 0
            
            # Pad the limit to exactly 16 digits
            s = str(limit).zfill(16)
            
            # Use Python's built-in memoization!
            @cache
            def f(i: int, unequal: bool, prev2: int) -> int:
                # Base case: successfully placed all 16 digits
                if i == 16: 
                    return 1
                
                # Check if current index lies on our target path
                flag = i in indices
                start = prev2 if flag else 0
                
                res = 0
                # Maximum digit we can place
                mx = 9 if unequal else int(s[i])
                
                for j in range(start, mx + 1):
                    nextprev2 = j if flag else prev2
                    # The boundary becomes unequal/free if we pick a digit smaller than max
                    res += f(i + 1, unequal or (j < mx), nextprev2)
                    
                return res

            # Fast-forward through leading zeros
            idx = 0
            for i in range(16):
                if s[i] != '0':
                    idx = i
                    break
                    
            prev2 = 0
            flag = idx in indices
            
            t = int(s[idx])
            ans = 0
            
            # Manually process the first non-zero digit to kick off the DP
            for i in range(t + 1):
                nextprev2 = i if flag else prev2
                
                if i == t:
                    ans += f(idx + 1, False, nextprev2) # Tight bound
                else:
                    ans += f(idx + 1, True, nextprev2)  # Free bound
            
            # Clear the cache to prevent interference between get(r) and get(l-1)
            f.cache_clear()
            return ans

        # Standard range DP calculation
        return get(r) - get(l - 1)