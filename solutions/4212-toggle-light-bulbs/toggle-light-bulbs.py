class Solution:
    def toggleLightBulbs(self, bulbs: list[int]) -> list[int]:

        d = defaultdict(int)
        for bulb in bulbs: d[bulb]^= 1

        return sorted(filter(lambda x: d[x], d))