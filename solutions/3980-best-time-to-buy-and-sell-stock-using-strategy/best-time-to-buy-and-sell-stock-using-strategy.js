function maxProfit(prices, strategy, k) {
    const n = prices.length;
    const profitSum = new Array(n + 1).fill(0);
    const priceSum = new Array(n + 1).fill(0);
    for (let i = 0; i < n; i++) {
        profitSum[i + 1] = profitSum[i] + prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    let res = profitSum[n];
    for (let i = k - 1; i < n; i++) {
        const leftProfit = profitSum[i - k + 1];
        const rightProfit = profitSum[n] - profitSum[i + 1];
        const changeProfit =
            priceSum[i + 1] - priceSum[i - Math.floor(k / 2) + 1];
        res = Math.max(res, leftProfit + changeProfit + rightProfit);
    }
    return res;
}