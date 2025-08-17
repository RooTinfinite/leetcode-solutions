from sortedcontainers import SortedSet
class StockPrice:

    def __init__(self):
        self.time_to_price = {}
        self.price_time = SortedSet()        
        self.current_timestamp = 0
        
    def update(self, timestamp: int, price: int) -> None:
        if timestamp in self.time_to_price:
            self.price_time.remove((self.time_to_price[timestamp], timestamp))
			
        self.price_time.add((price, timestamp))            
        self.time_to_price[timestamp] = price        
        self.current_timestamp = max(self.current_timestamp, timestamp)

    def current(self) -> int:
        return self.time_to_price[self.current_timestamp]

    def maximum(self) -> int:
        return self.price_time[-1][0]   

    def minimum(self) -> int:
        return self.price_time[0][0]