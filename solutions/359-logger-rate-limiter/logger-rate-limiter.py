class Logger:

    def __init__(self):
        self.history = set()  # set of past messages younger than 10 timesteps
        self.queue = list()  # ordered list of messages younger than 10 timesteps

    def shouldPrintMessage(self, timestamp: int, message: str) -> bool:
        q = self.queue
        h = self.history
        while self.queue and self.queue[0][0] <= timestamp - 10:
            self.history.remove(self.queue[0][1])
            self.queue.pop(0)
        if message in self.history:
            return False
        else:
            self.history.add(message)
            self.queue.append((timestamp, message))
            return True