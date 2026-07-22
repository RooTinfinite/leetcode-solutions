class Solution:
    def maxRatings(self, units: List[List[int]]) -> int:
        sum=0
        sum2=0
        firstmin=float('inf')
        secondmin=firstmin
        for i in units:
            first=float('inf')
            second=float('inf')
            for j in i:
                if j<first:
                    second=first
                    first=j
                elif j<second:
                    second=j
            if len(i)==1:
                second=0
            sum+=first
            sum2+=second
            firstmin=min(firstmin,first)
            secondmin=min(secondmin,second)
        return max(sum,firstmin+sum2-secondmin)
        