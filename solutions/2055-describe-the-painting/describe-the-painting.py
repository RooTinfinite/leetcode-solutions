from sortedcontainers import SortedDict
class Solution:
    def splitPainting(self, segments: List[List[int]]) -> List[List[int]]:
        
        # Build the sorted color dictionary.
        # colorDict[(start,end)] = color_sum
        colorDict = SortedDict()
        for (start, end, colorValue) in segments:
            colorDict[start] = colorDict.get(start,0) + colorValue
            colorDict[end] = colorDict.get(end,0) - colorValue

        # Iterate through the color dictioanry (this is already in chronological order), and get the value at each
        # point of change
        indices = colorDict.keys()
        numIntervals = len(indices) - 1
        ans = []
        colorValue = 0 # The colorValue will build on from what is is previously
        for idx in range(numIntervals):
            start = indices[idx]
            end = indices[idx+1]
            colorValue = colorValue + colorDict[start]
            if colorValue > 0:
                # Check for > 0, since we exclude parts that are not painted (i.e., exclude indices where colorValue = 0)
                ans.append([start, end, colorValue])
        
        return ans

"""
Edge case where there is a colorValue = 0:
[[4,16,12],[9,10,15],[18,19,13],[3,13,20],[12,16,3],[2,10,10],[3,11,4],[13,16,6]]
"""