class Leaderboard:

    def __init__(self):
        self.d = dict()
        

    def addScore(self, playerId: int, score: int) -> None:
        if playerId not in self.d:
            self.d[playerId] = 0
        self.d[playerId] += score
        

    def top(self, K: int) -> int:
        res = 0
        sortedd = sorted(self.d.items(), key=lambda x: x[1], reverse=True)
        print(sortedd)
        for i in range(K):
            print(sortedd[i][1])
            res += sortedd[i][1]
        return res
        

    def reset(self, playerId: int) -> None:
        self.d[playerId] = 0
        


# Your Leaderboard object will be instantiated and called as such:
# obj = Leaderboard()
# obj.addScore(playerId,score)
# param_2 = obj.top(K)
# obj.reset(playerId)