class Solution:
    def canChange(self, start: str, target: str) -> bool:
        if start == target:
            return True
        pending_L = 0   
        waiting_R = 0    

        for curr, goal in zip(start, target):
            if curr == 'R':
                if pending_L > 0:
                    return False
                waiting_R += 1  
            if goal == 'L':
                if waiting_R > 0:
                    return False
                pending_L += 1
            if goal == 'R':
                if waiting_R == 0:
                    return False
                waiting_R -= 1 
            if curr == 'L':
                if pending_L == 0:
                    return False
                pending_L -= 1    
        return pending_L == 0 and waiting_R == 0