class OrderManagementSystem {
    private orders: Map<number, [string, number]>;

    constructor() {
        this.orders = new Map();
    }

    addOrder(orderId: number, orderType: string, price: number): void {
        this.orders.set(orderId, [orderType, price]);
    }

    modifyOrder(orderId: number, newPrice: number): void {
        const data = this.orders.get(orderId);
        if (data) {
            data[1] = newPrice;
        }
    }

    cancelOrder(orderId: number): void {
        this.orders.delete(orderId);
    }

    getOrdersAtPrice(orderType: string, price: number): number[] {
        const result: number[] = [];
        for (const [orderId, data] of this.orders.entries()) {
            if (data[0] === orderType && data[1] === price) {
                result.push(orderId);
            }
        }
        return result;
    }
}