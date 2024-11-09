var maxProfit = function(prices) {
    let minPro = Number.MAX_SAFE_INTEGER;
    let maxPro = 0;
    for (let price of prices) {
        minPro = Math.min(price, minPro);
        maxPro = Math.max(maxPro, price - minPro);
    }
    return maxPro;
};