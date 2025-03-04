from collections import defaultdict
import math

class TweetCounts:

    def __init__(self):
        self.tweets = defaultdict(list)

    def recordTweet(self, tweetName: str, time: int) -> None:
        self.tweets[tweetName].append(time)

    def getTweetCountsPerFrequency(self, freq: str, tweetName: str, startTime: int, endTime: int):
        interval = {'minute': 60, 'hour': 3600, 'day': 86400}[freq]
        counts = [0] * ((endTime - startTime) // interval + 1)
        for time in self.tweets[tweetName]:
            if startTime <= time <= endTime:
                counts[(time - startTime) // interval] += 1
        return counts