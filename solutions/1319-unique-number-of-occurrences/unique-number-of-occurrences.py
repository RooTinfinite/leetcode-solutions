class Solution:
    def uniqueOccurrences(self, arr: List[int]) -> bool:
        arr.sort()
        v = []

        i = 0
        while i < len(arr):
            cnt = 1

            # Count occurrences of the current element
            while i + 1 < len(arr) and arr[i] == arr[i + 1]:
                cnt += 1
                i += 1

            v.append(cnt)
            i += 1

        v.sort()

        for i in range(1, len(v)):
            if v[i] == v[i - 1]:
                return False

        return True

