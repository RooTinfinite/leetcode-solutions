#Python3 Code
class Solution:
    def trimMean(self, arr: List[int]) -> float:
        m = len(arr)
        arr.sort()
        trimmed = (m * 5) // 100
        sm = 0
        for i in range(trimmed, m - trimmed):
            sm += arr[i]
        return sm / (m - (2 * trimmed))