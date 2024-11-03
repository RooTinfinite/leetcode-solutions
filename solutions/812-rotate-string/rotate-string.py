class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        # Get lengths of both strings
        n = len(s)
        m = len(goal)
        
        # If lengths are different, rotation is impossible
        if n != m:
            return False
            
        # Convert string to list for easier manipulation
        s_list = list(s)
        
        # Try all possible rotations
        for i in range(n):
            # If current string matches goal, we found a valid rotation
            if ''.join(s_list) == goal:
                return True
                
            # Perform one left rotation
            a = s_list[0]
            for j in range(n-1):
                s_list[j] = s_list[j+1]
            s_list[n-1] = a
            
        return False