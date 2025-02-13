"""
Complexity Analysis:
    - Time Complexity: O(n)
    - Space Complexity: O(n)
"""

class Solution:
    def find_most_frequent_number(self, nums):
        count = Counter(nums)
        most_frequent = max(count, key=count.get)
        return most_frequent

    def calculate_rotations(self, target, tops, bottoms):
        top_rotations = bottom_rotations = 0
        for i in range(len(tops)):
            if tops[i] != target and bottoms[i] != target:
                return -1
            if tops[i] != target:
                top_rotations += 1
            elif bottoms[i] != target:
                bottom_rotations += 1
        return min(top_rotations, bottom_rotations)

    def minDominoRotations(self, tops: List[int], bottoms: List[int]) -> int:
        most_frequent_top = self.find_most_frequent_number(tops)
        rotations_for_top = self.calculate_rotations(most_frequent_top, tops, bottoms)
        if rotations_for_top != -1:
            return rotations_for_top
        most_frequent_bottom = self.find_most_frequent_number(bottoms)
        rotations_for_bottom = self.calculate_rotations(most_frequent_bottom, tops, bottoms)
        return rotations_for_bottom