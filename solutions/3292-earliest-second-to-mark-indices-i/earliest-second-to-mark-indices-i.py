class Solution:
    def earliestSecondToMarkIndices(self, nums: List[int], changeIndices: List[int]) -> int:

        def allMarked(seconds: int)-> bool:
            marked = set()
            
            for i in range(seconds-1, -1, -1):
                seconds = min(seconds, i+1)

                if ch[i] not in marked:
                    seconds-= nums[ch[i]] + 1
                    if seconds < 0: return False
                    marked.add(ch[i])
                
            return len(marked) == n


        n = len(nums)
        ch = list(map(lambda x: x-1, changeIndices))

        idx = bisect_left(range(len(ch)), True, key = allMarked)

        return idx if allMarked(idx) else -1