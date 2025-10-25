/**
 * @param {number[]} transactions
 * @return {number}
 */
var maxTransactions = function (transactions) {
    let valueOfTransactions = 0;
    let numberOfTransactions = 0;
    const minHeapNegativeValuesIncludedInTransactions = new PriorityQueue((x, y) => x - y);

    for (let value of transactions) {

        if (value >= 0) {
            ++numberOfTransactions;
            valueOfTransactions += value;
            continue;
        }

        if (valueOfTransactions + value >= 0) {
            minHeapNegativeValuesIncludedInTransactions.enqueue(value);
            ++numberOfTransactions;
            valueOfTransactions += value;
            continue;
        }

        if (!minHeapNegativeValuesIncludedInTransactions.isEmpty() && minHeapNegativeValuesIncludedInTransactions.front() < value) {
            valueOfTransactions += value - minHeapNegativeValuesIncludedInTransactions.dequeue();
            minHeapNegativeValuesIncludedInTransactions.enqueue(value);
        }
    }

    return numberOfTransactions;
};