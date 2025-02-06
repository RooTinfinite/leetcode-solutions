class Solution:
    def distributeCandies(self, candyType: List[int]) -> int:
        # half length of candyType list
        candy_len = int(len(candyType)/2)
        # no of of unique candies 
        unique_candy_len = len(set(candyType))
        return min(candy_len,unique_candy_len)