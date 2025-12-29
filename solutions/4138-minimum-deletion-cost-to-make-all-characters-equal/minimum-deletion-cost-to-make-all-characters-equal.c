long long minCost(char* s, int* cost, int costSize) {
    long long* hash = (long long*)calloc(26, sizeof(long long));
    long long total_cost = 0 , max_cost = 0;
    for(int i = 0; i < costSize; i++) {
        total_cost += cost[i];
        hash[s[i] - 'a'] += cost[i];
        if(hash[s[i] - 'a'] > max_cost) max_cost = hash[s[i] - 'a'];
    }
    free(hash);
    return total_cost - max_cost;
}