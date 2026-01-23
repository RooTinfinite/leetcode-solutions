class Node extends DoublyLinkedListNode {
    constructor(
        public value: number,
        public left: number,
    ) {
        super(value);
    }
}

interface Pair {
    first: Node;
    second: Node;
    cost: number;
}

function minimumPairRemoval(nums: number[]): number {
    const pq = new PriorityQueue<Pair>((a, b) =>
        a.cost === b.cost ? a.first.left - b.first.left : a.cost - b.cost,
    );
    const list = new DoublyLinkedList<Node>();
    const merged = new Array<boolean>(nums.length).fill(false);

    let decreaseCount = 0;
    let count = 0;
    list.insertLast(new Node(nums[0], 0));

    for (let i = 1; i < nums.length; i++) {
        list.insertLast(new Node(nums[i], i));

        const curr = list.tail();
        pq.enqueue({
            first: curr.getPrev() as Node,
            second: curr,
            cost: nums[i] + nums[i - 1],
        });

        if (nums[i - 1] > nums[i]) {
            decreaseCount++;
        }
    }

    while (decreaseCount > 0) {
        const { first, second, cost } = pq.dequeue()!;
        if (
            merged[first.left] ||
            merged[second.left] ||
            first.value + second.value !== cost
        )
            continue;
        count++;

        if (first.value > second.value) {
            decreaseCount--;
        }

        const prev = first.getPrev() as Node | null;
        const next = second.getNext() as Node | null;

        if (prev) {
            if (prev.value > first.value && prev.value <= cost) {
                decreaseCount--;
            }
            if (prev.value <= first.value && prev.value > cost) {
                decreaseCount++;
            }

            pq.enqueue({
                first: prev,
                second: first,
                cost: prev.value + cost,
            });
        }

        if (next) {
            if (second.value > next.value && cost <= next.value) {
                decreaseCount--;
            }
            if (second.value <= next.value && cost > next.value) {
                decreaseCount++;
            }

            pq.enqueue({
                first: first,
                second: next,
                cost: cost + next.value,
            });
        }

        list.remove(second);
        first.value = cost;
        merged[second.left] = true;
    }

    return count;
}