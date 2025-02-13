from collections import defaultdict
import bisect

class TopVotedCandidate:
    def __init__(self, persons: List[int], times: List[int]):
        self.leaders = []
        self.times = times
        votes = defaultdict(int)
        leader = -1
        
        for i in range(len(persons)):
            votes[persons[i]] += 1
            if leader == -1 or votes[persons[i]] >= votes[leader]:
                leader = persons[i]
            self.leaders.append(leader)

    def q(self, t: int) -> int:
        idx = bisect.bisect_right(self.times, t) - 1
        return self.leaders[idx]