class Solution:
    def maximumBeauty(self, items: List[List[int]], queries: List[int]) -> List[int]:
        items.sort(key=lambda x: x[0])
        n = len(items)
        max_beauties = [0] * n
        max_beauties[0] = items[0][1]
        
        for i in range(1, n):
            max_beauties[i] = max(max_beauties[i-1], items[i][1])
        
        def binary_search(target):
            left, right = 0, len(items) - 1
            result = -1
            
            while left <= right:
                mid = left + (right - left) // 2
                if items[mid][0] <= target:
                    result = mid
                    left = mid + 1
                else:
                    right = mid - 1
            return result
        
        return [0 if binary_search(q) < 0 else max_beauties[binary_search(q)] for q in queries]