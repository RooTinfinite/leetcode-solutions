class Solution:
    def brokenCalc(self, startValue: int, target: int) -> int:
        t = target
        sv = startValue
        num_operations = 0

        while t > sv:
            if t % 2 == 0:
                t = t // 2
                num_operations += 1
            
            elif t % 2 != 0:
                t = t + 1
                num_operations += 1
        
        if t < sv:
            num_operations += (sv - t)
        
        return num_operations