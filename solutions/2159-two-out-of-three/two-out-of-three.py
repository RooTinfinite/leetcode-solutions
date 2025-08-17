class Solution:
    def twoOutOfThree(self, nums1: List[int], nums2: List[int], nums3: List[int]) -> List[int]:
        vidai=[]
        for j in nums1:
            if j in nums2 or j in nums3:
                if j not in vidai:

                    vidai.append(j)
        for j in nums2:
            if j in nums1 or j in nums3:
                if j not in vidai:

                    vidai.append(j)
        for j in nums3:
            if j in nums2 or j in nums1:
                if j not in vidai:

                    vidai.append(j)
        return vidai