class Solution(object):
    def stableMountains(self, height, threshold):
        l = []
        for i in range(1,len(height)):
            if height[i-1] > threshold :
                l.append(i)
        return l  