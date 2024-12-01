class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        if arr.count(0) > 1:
            return True
        
        numset = set(arr) - {0}
        for n in arr:
            if 2*n in numset:
                return True
        return False