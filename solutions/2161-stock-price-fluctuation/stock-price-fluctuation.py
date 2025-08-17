import heapq


class StockPrice:

    # SC: O(n), where n is num of records sent including duplicates
    def __init__(self):
        self.record = {}
        self.max_heap = []  # (price, timestamp)
        self.min_heap = []  # (price, timestamp)
        self.latest_stamp = -float("inf")

    # TC: O(log n)
    def update(self, timestamp: int, price: int) -> None:
        if self.latest_stamp < timestamp:
            self.latest_stamp = timestamp

        self.record[timestamp] = price
        
        heapq.heappush(self.max_heap, (-price, timestamp))
        heapq.heappush(self.min_heap, (price, timestamp))

    def current(self) -> int:
        return self.record[self.latest_stamp]

    # TC: O(n log n)
    def maximum(self) -> int:
        while self.max_heap:
            price, ts = self.max_heap[0]
            if -price == self.record[ts]:
                return -price
            heapq.heappop(self.max_heap)
        return -1

    # TC: O(n log n)
    def minimum(self) -> int:
        while self.min_heap:
            price, ts = self.min_heap[0]
            if price == self.record[ts]:
                return price
            heapq.heappop(self.min_heap)
        return -1

