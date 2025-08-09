class Solution:
    def findPeakGrid(self, mat: List[List[int]]) -> List[int]:
        rows=len(mat)
        cols=len(mat[0])
        low=0
        high=cols-1
        while low<=high:
            mid=(low+high)//2
            max_row=0
            for row in range(rows):
                if mat[row][mid] > mat[max_row][mid]:
                    max_row = row
            leftbig= (mid-1>=0 and mat[max_row][mid]<mat[max_row][mid-1])
            rightbig=(mid<cols-1 and mat[max_row][mid]<mat[max_row][mid+1])
            if not leftbig and not rightbig:
                return [max_row,mid]
            elif leftbig:
                high=mid-1
            else:
                low=mid+1