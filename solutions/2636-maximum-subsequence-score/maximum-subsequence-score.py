class Solution:
    def maxScore(self, nums1, nums2, k):
        result = 0
        totalSum = 0
        heap = []

        merged = [(nums2[i], nums1[i]) for i in range(len(nums1))]
        merged.sort(reverse=True)

        for maxOf2, num1Val in merged:
            if len(heap) == k:
                totalSum -= heapq.heappop(heap)

            totalSum += num1Val
            heapq.heappush(heap, num1Val)

            if len(heap) == k:
                result = max(result, totalSum * maxOf2)

        return result