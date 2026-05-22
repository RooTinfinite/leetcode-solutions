class OrderManagementSystem:

    def __init__(self):
        self.orders = {} # orderId: (orderType, price)
        self.priceToOrders = {"buy": defaultdict(list), "sell": defaultdict(list)} # {"buy": {price: []}, "sell": {price: []}}

    def addOrder(self, orderId: int, orderType: str, price: int) -> None:
        orders = self.priceToOrders[orderType][price]
        idx = len(orders)
        orders.append(orderId)
        self.orders[orderId] = [orderType, price, idx]

    def modifyOrder(self, orderId: int, newPrice: int) -> None:
        # remove from old array
        oldPrice = self.orders[orderId][1]
        orderType = self.orders[orderId][0]
        oldIdx = self.orders[orderId][2]
        oldOrders = self.priceToOrders[orderType][oldPrice]
        if len(oldOrders) == 1:
            oldOrders.pop()
        else:
            last_idx = len(oldOrders) - 1
            last_order = oldOrders[last_idx]
            tmp = last_order # an order id
            oldOrders[last_idx] = orderId
            oldOrders[oldIdx] = tmp
            self.orders[tmp][2] = oldIdx
            oldOrders.pop()
        # add to new
        orders = self.priceToOrders[orderType][newPrice]
        idx = len(orders)
        orders.append(orderId)
        self.orders[orderId] = [orderType, newPrice, idx]

    def cancelOrder(self, orderId: int) -> None:
        # remove from old array
        oldPrice = self.orders[orderId][1]
        orderType = self.orders[orderId][0]
        oldIdx = self.orders[orderId][2]
        oldOrders = self.priceToOrders[orderType][oldPrice]
        if len(oldOrders) == 1:
            oldOrders.pop()
        else:
            last_idx = len(oldOrders) - 1
            last_order = oldOrders[last_idx]
            tmp = last_order # an order id
            oldOrders[last_idx] = orderId
            oldOrders[oldIdx] = tmp
            self.orders[tmp][2] = oldIdx
            oldOrders.pop()
        del self.orders[orderId]

    def getOrdersAtPrice(self, orderType: str, price: int) -> List[int]:
        return self.priceToOrders[orderType][price]


# Your OrderManagementSystem object will be instantiated and called as such:
# obj = OrderManagementSystem()
# obj.addOrder(orderId,orderType,price)
# obj.modifyOrder(orderId,newPrice)
# obj.cancelOrder(orderId)
# param_4 = obj.getOrdersAtPrice(orderType,price)