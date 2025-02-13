class Solution:
    def reorderedPowerOf2(self, n):
        dict1 = Counter(str(n))

        for i in range(31):
            if dict1 == Counter(str(1<<i)):
                return True 

        return False