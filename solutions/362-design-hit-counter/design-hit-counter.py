class HitCounter:
    def __init__(self):
        self.hits = [(0, 0)] * 300
        
    def hit(self, timestamp: int) -> None:
        i = (timestamp-1) % 300
        t, c = self.hits[i]
        
        if timestamp - t < 300: 
            self.hits[i] = (timestamp, c+1)
        else:
            self.hits[i] = (timestamp, 1)
            
    def getHits(self, timestamp: int) -> int:
        count = 0
        for t, c in self.hits:
            if timestamp - t < 300:
                count += c
        return count