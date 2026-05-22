import java.util.*;

class OrderManagementSystem {
    Map<String, Map<Integer, Set<Integer>>> table;
    Map<Integer, String> orderIdToOrderType;
    Map<Integer, Integer> orderIdToPrice;

    public OrderManagementSystem() {
        table = new HashMap<>();
        orderIdToOrderType = new HashMap<>();
        orderIdToPrice = new HashMap<>();
    }
    
    public void addOrder(int orderId, String orderType, int price) {
        table.putIfAbsent(orderType, new HashMap<>());
        table.get(orderType).putIfAbsent(price, new HashSet<>());
        table.get(orderType).get(price).add(orderId);
        orderIdToOrderType.put(orderId, orderType);
        orderIdToPrice.put(orderId, price);
    }
    
    public void modifyOrder(int orderId, int newPrice) {
        String orderType = orderIdToOrderType.get(orderId);
        int price = orderIdToPrice.get(orderId);
        if (price == newPrice) {
            return;
        }
        table.get(orderType).get(price).remove(orderId);
        table.get(orderType).putIfAbsent(newPrice, new HashSet<>());
        table.get(orderType).get(newPrice).add(orderId);
        orderIdToPrice.put(orderId, newPrice);
        cleanupTable(orderType, price);
    }
    
    public void cancelOrder(int orderId) {
        String orderType = orderIdToOrderType.get(orderId);
        int price = orderIdToPrice.get(orderId);
        table.get(orderType).get(price).remove(orderId);
        cleanupTable(orderType, price);
    }
    
    public int[] getOrdersAtPrice(String orderType, int price) {
        if (!table.containsKey(orderType) || !table.get(orderType).containsKey(price)) {
            return new int[0];
        }
        Set<Integer> set = table.get(orderType).get(price);
        int n = set.size();
        int[] activeOrderIds = new int[n];
        Iterator<Integer> iter = set.iterator();
        int i = 0;
        while (iter.hasNext()) {
            activeOrderIds[i++] = iter.next();
        }
        return activeOrderIds;
    }

    private void cleanupTable(String orderType, int price) { // Optional
        if (table.get(orderType).get(price).isEmpty()) {
            table.get(orderType).remove(price);
            if (table.get(orderType).isEmpty()) {
                table.remove(orderType);
            }
        }
    }
}

/**
 * Your OrderManagementSystem object will be instantiated and called as such:
 * OrderManagementSystem obj = new OrderManagementSystem();
 * obj.addOrder(orderId,orderType,price);
 * obj.modifyOrder(orderId,newPrice);
 * obj.cancelOrder(orderId);
 * int[] param_4 = obj.getOrdersAtPrice(orderType,price);
 */