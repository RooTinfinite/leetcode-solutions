class AuctionSystem {
    HashMap<Integer, HashMap<Integer, Integer>> bids = new HashMap<>();
    HashMap<Integer, PriorityQueue<int[]>> queue = new HashMap<>();

    AuctionSystem() {}

    void addBid(int userId, int itemId, int bidAmount) {
        bids.computeIfAbsent(itemId, k -> new HashMap<>()).put(userId, bidAmount);
        queue.computeIfAbsent(itemId, k -> new PriorityQueue<>(
                (a, b) -> a[0] != b[0] ? b[0] - a[0] : b[1] - a[1]
        )).add(new int[]{bidAmount, userId});
    }

    void updateBid(int userId, int itemId, int newAmount) {
        addBid(userId, itemId, newAmount);
    }

    void removeBid(int userId, int itemId) {
        bids.computeIfAbsent(itemId, k -> new HashMap<>()).remove(userId);
    }

    int getHighestBidder(int itemId) {
        HashMap<Integer, Integer> b = bids.computeIfAbsent(itemId, k -> new HashMap<>());
        PriorityQueue<int[]> q = queue.computeIfAbsent(itemId, k -> new PriorityQueue<>(
                (a, c) -> a[0] != c[0] ? c[0] - a[0] : c[1] - a[1]
        ));

        while (!q.isEmpty()) {
            int[] top = q.peek();
            int amt = top[0], uid = top[1];
            Integer cur = b.get(uid);
            int val = (cur == null ? -1 : cur);
            if (val == amt)
                return uid;
            q.poll();
        }

        return -1;
    }
}