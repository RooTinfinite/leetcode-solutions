class Solution:
    def minimumIndex(self, capacity: list[int], 
                           itemSize: int) -> int:

        res, idx = inf, -1

        for i, cap in enumerate(capacity):
            if itemSize <= cap < res:
                res, idx = cap, i
                 
        return idx 
        