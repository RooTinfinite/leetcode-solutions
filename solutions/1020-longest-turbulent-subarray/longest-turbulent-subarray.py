class Solution:
    def maxTurbulenceSize(self, arr: List[int]) -> int:
        best = curr = lastDiff = 0
        
        for i in range( 0, len(arr) - 1 ):
            diff = arr[i] - arr[i+1]
            if lastDiff == 0:
                lastDiff = diff * -1
            if diff * lastDiff < 0:
                curr += 1
                if best < curr: 
                    best = curr
            elif diff * lastDiff > 0:
                curr = 1
            else:
                curr = 0
            lastDiff = diff
        return best + 1