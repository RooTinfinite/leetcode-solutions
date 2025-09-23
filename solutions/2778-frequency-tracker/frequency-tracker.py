class FrequencyTracker:

    def __init__(self):
        self.num2freq = dict()
        self.freq_count = dict()

    def reduce_freq(self, freq):
        self.freq_count[freq] -= 1
        if self.freq_count[freq] == 0:
            del self.freq_count[freq]

    def increase_freq(self, freq):
        if freq not in self.freq_count:
            self.freq_count[freq] = 0
        self.freq_count[freq] += 1 

    def add(self, number: int) -> None:
        if number not in self.num2freq:
            self.num2freq[number] = 0
        self.num2freq[number] += 1
        freq = self.num2freq[number]
        if freq > 1:
            self.reduce_freq(freq - 1)
        self.increase_freq(freq)

    def deleteOne(self, number: int) -> None:
        if number not in self.num2freq:
            return
        self.reduce_freq(self.num2freq[number])
        self.num2freq[number] -= 1
        if self.num2freq[number] == 0:
            del self.num2freq[number]
            return 
        self.increase_freq(self.num2freq[number])

    def hasFrequency(self, frequency: int) -> bool:
        return frequency in self.freq_count


# Your FrequencyTracker object will be instantiated and called as such:
# obj = FrequencyTracker()
# obj.add(number)
# obj.deleteOne(number)
# param_3 = obj.hasFrequency(frequency)