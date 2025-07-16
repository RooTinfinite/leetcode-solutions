class Solution:
    def maximumUnits(self, boxTypes, truckSize):
        queue = sorted(boxTypes, key=lambda x: x[1], reverse=True)
        unitCount = 0
        while len(queue) != 0:
            top = queue.pop(0)
            boxCount = min(truckSize, top[0])
            unitCount += boxCount * top[1]
            truckSize -= boxCount
            if truckSize == 0:
                break
        return unitCount