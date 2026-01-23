public class Node {
    public long value;
    public int left;
    public Node prev;
    public Node next;

    public Node(long value, int left) {
        this.value = value;
        this.left = left;
    }
}

public class Item : IComparable<Item> {
    public Node first;
    public Node second;
    public long cost;

    public Item(Node first, Node second, long cost) {
        this.first = first;
        this.second = second;
        this.cost = cost;
    }

    public int CompareTo(Item other) {
        if (cost == other.cost) {
            return first.left.CompareTo(other.first.left);
        }
        return cost.CompareTo(other.cost);
    }
}

public class Solution {
    public int MinimumPairRemoval(int[] nums) {
        var pq = new PriorityQueue<Item, Item>();
        bool[] merged = new bool[nums.Length];
        int decreaseCount = 0;
        int count = 0;
        List<Node> nodes = new List<Node>();
        nodes.Add(new Node(nums[0], 0));

        for (int i = 1; i < nums.Length; i++) {
            nodes.Add(new Node(nums[i], i));
            nodes[i - 1].next = nodes[i];
            nodes[i].prev = nodes[i - 1];
            var item = new Item(nodes[i - 1], nodes[i],
                                nodes[i - 1].value + nodes[i].value);
            pq.Enqueue(item, item);

            if (nums[i - 1] > nums[i]) {
                decreaseCount++;
            }
        }

        while (decreaseCount > 0) {
            var item = pq.Dequeue();
            Node first = item.first;
            Node second = item.second;
            long cost = item.cost;

            if (merged[first.left] || merged[second.left] ||
                first.value + second.value != cost) {
                continue;
            }
            count++;
            if (first.value > second.value) {
                decreaseCount--;
            }

            Node prevNode = first.prev;
            Node nextNode = second.next;
            first.next = nextNode;
            if (nextNode != null) {
                nextNode.prev = first;
            }

            if (prevNode != null) {
                if (prevNode.value > first.value && prevNode.value <= cost) {
                    decreaseCount--;
                } else if (prevNode.value <= first.value &&
                           prevNode.value > cost) {
                    decreaseCount++;
                }
                var newItem = new Item(prevNode, first, prevNode.value + cost);
                pq.Enqueue(newItem, newItem);
            }

            if (nextNode != null) {
                if (second.value > nextNode.value && cost <= nextNode.value) {
                    decreaseCount--;
                } else if (second.value <= nextNode.value &&
                           cost > nextNode.value) {
                    decreaseCount++;
                }
                var newItem = new Item(first, nextNode, cost + nextNode.value);
                pq.Enqueue(newItem, newItem);
            }

            first.value = cost;
            merged[second.left] = true;
        }

        return count;
    }
}