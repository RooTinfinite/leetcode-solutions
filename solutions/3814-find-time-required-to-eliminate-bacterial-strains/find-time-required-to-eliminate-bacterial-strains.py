class Solution:
    def minEliminationTime(self, timeReq: List[int], splitTime: int) -> int:

        heapify(timeReq)
        heappop(timeReq)
        
        while timeReq:
            bact = splitTime + heappop(timeReq)
            heappushpop(timeReq, bact)

        return bact