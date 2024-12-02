from sortedcontainers import SortedList

class StatisticsTracker:

    def __init__(self):
        self.a = deque()
        self.n = 0
        self.s = 0
        self.ct = defaultdict(int)
        self.pq = []
        self.sd = SortedList()

    def addNumber(self, number: int) -> None:
        self.sd.add(number)
        self.ct[number] += 1
        heappush(self.pq, (-self.ct[number], number))
        self.s += number
        self.a.append(number)
        self.n+= 1
        
    def removeFirstAddedNumber(self) -> None:
        number = self.a.popleft()
        self.sd.remove(number)
        self.ct[number]-= 1
        self.s-= number
        self.n-= 1

    def getMean(self) -> int:
        return self.s // self.n

    def getMedian(self) -> int:
        return self.sd[self.n // 2]

    def getMode(self) -> int:
        while self.pq and -self.pq[0][0] != self.ct[self.pq[0][1]]: heappop(self.pq)
        return self.pq[0][1]