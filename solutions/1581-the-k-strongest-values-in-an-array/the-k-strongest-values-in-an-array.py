class Solution:
    def getStrongest(self, arr: List[int], k: int) -> List[int]:
        arr.sort()
        i, j = 0, len(arr) - 1
        median = arr[(len(arr) - 1) // 2]
        while len(arr) + i - j <= k:
            if median - arr[i] > arr[j] - median:
                i = i + 1
            else:
                j = j - 1
        return arr[:i] + arr[j + 1:]