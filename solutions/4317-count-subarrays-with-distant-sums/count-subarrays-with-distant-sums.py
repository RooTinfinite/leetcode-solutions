class Solution:
    def distantSubarrays(self, nums: list[int], goal: int, k: int) -> int:

        n = len(nums)

        # If k == 0, every subarray is distant
        if k == 0:
            return n * (n + 1) // 2

        # Build prefix sum
        prefix = [0] * (n + 1)

        for i in range(n):
            prefix[i + 1] = prefix[i] + nums[i]

        count = 0

        def merge(low, mid, high):
            nonlocal count

            left = prefix[low:mid + 1]
            right = prefix[mid + 1:high + 1]

            # Count non-distant cross pairs
            a = 0
            b = 0

            for x in right:

                L = x - goal - k
                R = x - goal + k

                while a < len(left) and left[a] <= L:
                    a += 1

                while b < len(left) and left[b] < R:
                    b += 1

                count += b - a

            # Normal merge
            i = 0
            j = 0
            temp = []

            while i < len(left) and j < len(right):

                if left[i] <= right[j]:
                    temp.append(left[i])
                    i += 1
                else:
                    temp.append(right[j])
                    j += 1

            while i < len(left):
                temp.append(left[i])
                i += 1

            while j < len(right):
                temp.append(right[j])
                j += 1

            prefix[low:high + 1] = temp

        def mergeSort(low, high):

            if low >= high:
                return

            mid = low + (high - low) // 2

            mergeSort(low, mid)
            mergeSort(mid + 1, high)

            merge(low, mid, high)

        mergeSort(0, n)

        total = n * (n + 1) // 2

        # Distant = Total - Non-distant
        return total - count