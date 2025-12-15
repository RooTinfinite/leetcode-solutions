function getDescentPeriods(prices: number[]): number {
    const n = prices.length;
    let res: number = 1; // total number of smooth descending periods, initial value is dp[0]
    let prev: number = 1; // total number of smooth descending periods ending with the previous element, initial value is dp[0]
    // traverse the array starting from 1, and update prev and the total res according to the recurrence relation
    for (let i = 1; i < n; ++i) {
        if (prices[i] === prices[i - 1] - 1) {
            ++prev;
        } else {
            prev = 1;
        }
        res += prev;
    }
    return res;
}