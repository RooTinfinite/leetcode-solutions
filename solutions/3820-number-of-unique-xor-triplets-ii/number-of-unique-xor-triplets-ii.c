int uniqueXorTriplets(int* nums, int numsSize) {
    int m = 0;
    for (int i = 0; i < numsSize; i++) {
        m = fmax(m, nums[i]);
    }
    int u = 1;
    while (u <= m) {
        u <<= 1;
    }
    bool* s = (bool*)calloc(u, sizeof(bool));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i; j < numsSize; j++) {
            s[nums[i] ^ nums[j]] = true;
        }
    }
    bool* t = (bool*)calloc(u, sizeof(bool));
    for (int x = 0; x < u; x++) {
        if (!s[x]) {
            continue;
        }
        for (int k = 0; k < numsSize; k++) {
            t[x ^ nums[k]] = true;
        }
    }
    int ans = 0;
    for (int x = 0; x < u; x++) {
        if (t[x]) {
            ans++;
        }
    }
    free(s);
    free(t);
    return ans;
}