class Solution:
    def maximumWhiteTiles(self, tiles: List[List[int]], carpetLen: int) -> int:
        # sort the tiles by the starting position
        tiles.sort(key = lambda x:x[0])
        # build the starting position array
        startPos = [tiles[i][0] for i in range(len(tiles))]
        # build the prefix sum array
        preSum = [0] * (len(tiles) + 1)
        for i in range(1, len(tiles) + 1):
            preSum[i] = preSum[i - 1] + (tiles[i-1][1]-tiles[i-1][0] + 1)
        
        res = 0
        for i in range(len(tiles)):
            s, e = tiles[i]
            # if the length of tile >= length of carpet, return carpetLen
            if e >= s + carpetLen - 1:
                return carpetLen
            # binary search the index of the ending tile that the carpet can partially cover
            endIdx = bisect_right(startPos, s + carpetLen - 1) - 1
            # calculate the length of the ending tile that the carpet cannot cover 
            compensate = 0
            if tiles[endIdx][1] > s + carpetLen - 1:
                compensate = tiles[endIdx][1] - s - carpetLen + 1
            # update the result
            res = max(res, preSum[endIdx+1] - preSum[i] - compensate)
            
        return res