class Solution(object):
    def smallestCommonElement(self, mat):
        """
        :type mat: List[List[int]]
        :rtype: int
        """
        for element in mat[0]:
            flag = True
            for row in mat[1:]:
                if not self.binarySearch(row, element):
                    flag = False
                    break
            if flag: return element
        return -1
    
    def binarySearch(self, arr, ele):
        if arr and arr[0] >  ele:  return False
        if arr and arr[-1] < ele: return False
        i = 0
        j = len(arr)-1
        while i <= j:
            mid = (i + j)//2
            if arr[mid] == ele: return True
            elif arr[mid] < ele: i = mid + 1
            else: j = mid - 1
        return False