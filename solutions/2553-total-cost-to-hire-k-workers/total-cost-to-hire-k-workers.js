var totalCost = function (costs, k, candidates) {
    let n = costs.length;
    let total = 0;
    let queue = new PriorityQueue({compare: (a, b) => {
        if (a[0] === b[0]) return a[1] - b[1];
        return a[0] - b[0];
    }});

    let left = 0;
    let right = n - 1;

    for (let i = 0; i < candidates; i++) {
        if (left <= right) {
            queue.enqueue([costs[left], left]);
            left++;
        }
        if (left <= right) {
            queue.enqueue([costs[right], right]);
            right--;
        }
    }
    for (let i = 0; i < k; i++) {
        let [cost, index] = queue.dequeue();
        total += cost;

        if (index < left) {
            if (left <= right) {
                queue.enqueue([costs[left], left]);
                left++;
            }
        } else {
            if (left <= right) {
                queue.enqueue([costs[right], right]);
                right--;
            }
        }
    }
    return total;
};