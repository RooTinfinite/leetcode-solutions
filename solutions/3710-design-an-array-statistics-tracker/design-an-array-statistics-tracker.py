from sortedcontainers import SortedList

class StatisticsTracker:

    def __init__(self):
        self.queue = []
        self.freq = {}
        self.freqfreq = {}
        self.sl = SortedList([])
        self.freqsl = SortedList([])
        self.s = 0
        self.n = 0
        

    def addNumber(self, number: int) -> None:
        self.queue.append(number)
        if number not in self.freq:self.freq[number] = 0
        self.freq[number] += 1
        if self.freq[number] not in self.freqfreq:
            self.freqfreq[self.freq[number]] = SortedList([])
        if self.freq[number] > 1:
            self.freqfreq[self.freq[number]-1].remove(number)
            self.freqsl.remove(self.freq[number]-1)
        self.freqsl.add(self.freq[number])
        self.freqfreq[self.freq[number]].add(number)

        self.sl.add(number)
        self.s += number
        self.n += 1 
        

    def removeFirstAddedNumber(self) -> None:
        if not self.queue:return 
        torem = self.queue[0]
        self.queue.pop(0)
        toremfreq = self.freq[torem]
        self.freq[torem] -= 1
        self.freqsl.remove(toremfreq)
        self.freqfreq[toremfreq].remove(torem)
        if toremfreq > 1:
            self.freqsl.add(toremfreq-1)
            self.freqfreq[toremfreq-1].add(torem)
        self.sl.remove(torem)
        self.s -= torem
        self.n -= 1
        

    def getMean(self) -> int:
        return self.s // self.n if self.n > 0 else 0
        

    def getMedian(self) -> int:
        if self.n == 0:return 0
        return self.sl[self.n//2]


    def getMode(self) -> int:
        M = self.freqsl[-1]
        return self.freqfreq[M][0]



# Your StatisticsTracker object will be instantiated and called as such:
# obj = StatisticsTracker()
# obj.addNumber(number)
# obj.removeFirstAddedNumber()
# param_3 = obj.getMean()
# param_4 = obj.getMedian()
# param_5 = obj.getMode()