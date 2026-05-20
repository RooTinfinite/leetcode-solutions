class AuctionSystem:
    def __init__(self):
        self.bids = defaultdict(dict)
        self.queue  = defaultdict(list)

    def addBid(self, userId: int, itemId: int, bidAmount: int) -> None:
        self.bids[itemId][userId] = bidAmount
        heapq.heappush(self.queue[itemId], (-bidAmount, -userId))

    def updateBid(self, userId: int, itemId: int, newAmount: int) -> None:
        self.addBid(userId, itemId, newAmount)

    def removeBid(self, userId: int, itemId: int) -> None:
        del self.bids[itemId][userId]

    def getHighestBidder(self, itemId: int) -> int:
        bids = self.bids[itemId]
        queue = self.queue[itemId]

        while queue:
            amt, uid = -queue[0][0], -queue[0][1]
            if bids.get(uid, -1) == amt:
                return uid
            heapq.heappop(queue)

        return -1