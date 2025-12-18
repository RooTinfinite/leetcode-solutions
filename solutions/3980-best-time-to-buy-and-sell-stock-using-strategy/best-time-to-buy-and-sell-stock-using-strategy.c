long long maxProfit(int* prices, int pricesSize, int* strategy,
                    int strategySize, int k) {
    int n = pricesSize;
    long long* profitSum = (long long*)calloc(n + 1, sizeof(long long));
    long long* priceSum = (long long*)calloc(n + 1, sizeof(long long));
    for (int i = 0; i < n; i++) {
        profitSum[i + 1] = profitSum[i] + (long long)prices[i] * strategy[i];
        priceSum[i + 1] = priceSum[i] + prices[i];
    }
    long long res = profitSum[n];
    for (int i = k - 1; i < n; i++) {
        long long leftProfit = profitSum[i - k + 1];
        long long rightProfit = profitSum[n] - profitSum[i + 1];
        long long changeProfit = priceSum[i + 1] - priceSum[i - k / 2 + 1];
        long long total = leftProfit + changeProfit + rightProfit;
        if (total > res) res = total;
    }
    free(profitSum);
    free(priceSum);
    return res;
}