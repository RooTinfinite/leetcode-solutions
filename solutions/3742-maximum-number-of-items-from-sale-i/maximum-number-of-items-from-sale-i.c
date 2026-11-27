int maximumSaleItems(int** items, int itemsSize, int* itemsColSize,
                     int budget) {
    int* f = (int*)calloc(budget + 1, sizeof(int));
    int mn = items[0][1];
    for (int i = 0; i < itemsSize; i++) {
        int factor = items[i][0], price = items[i][1];
        if (price < mn) {
            mn = price;
        }
        int cnt = 0;
        for (int k = 0; k < itemsSize; k++) {
            if (items[k][0] % factor == 0) {
                cnt++;
            }
        }
        for (int j = budget; j >= price; j--) {
            if (f[j - price] + cnt > f[j]) {
                f[j] = f[j - price] + cnt;
            }
        }
    }
    int ans = 0;
    for (int j = 0; j <= budget; j++) {
        int cur = f[j] + (budget - j) / mn;
        if (cur > ans) {
            ans = cur;
        }
    }
    free(f);
    return ans;
}