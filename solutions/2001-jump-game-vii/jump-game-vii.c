bool canReach(char* s, int minJump, int maxJump) {
    int n = strlen(s);
    int* f = (int*)calloc(n, sizeof(int));
    int* pre = (int*)malloc(n * sizeof(int));
    f[0] = 1;
    // since we start dynamic programming from i=minJump, we need to precompute
    // the prefix sums for the part [0, minJump)
    for (int i = 0; i < minJump; i++) {
        pre[i] = 1;
    }
    for (int i = minJump; i < n; i++) {
        int left = i - maxJump;
        int right = i - minJump;
        if (s[i] == '0') {
            int total = pre[right];
            if (left > 0) {
                total -= pre[left - 1];
            }
            f[i] = total != 0 ? 1 : 0;
        }
        pre[i] = pre[i - 1] + f[i];
    }
    bool result = (f[n - 1] == 1);
    free(f);
    free(pre);
    return result;
}