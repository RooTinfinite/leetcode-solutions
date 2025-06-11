int getStatus(int cnt_a, int cnt_b) { return ((cnt_a & 1) << 1) | (cnt_b & 1); }

int maxDifference(char* s, int k) {
    int n = strlen(s);
    int ans = INT_MIN;

    for (char a = '0'; a <= '4'; ++a) {
        for (char b = '0'; b <= '4'; ++b) {
            if (a == b) {
                continue;
            }
            int best[4] = {INT_MAX, INT_MAX, INT_MAX, INT_MAX};
            int cnt_a = 0, cnt_b = 0;
            int prev_a = 0, prev_b = 0;
            int left = -1;
            for (int right = 0; right < n; ++right) {
                cnt_a += (s[right] == a) ? 1 : 0;
                cnt_b += (s[right] == b) ? 1 : 0;

                while (right - left >= k && cnt_b - prev_b >= 2) {
                    int left_status = getStatus(prev_a, prev_b);
                    if (prev_a - prev_b < best[left_status]) {
                        best[left_status] = prev_a - prev_b;
                    }
                    ++left;
                    prev_a += (s[left] == a) ? 1 : 0;
                    prev_b += (s[left] == b) ? 1 : 0;
                }

                int right_status = getStatus(cnt_a, cnt_b);
                if (best[right_status ^ 0b10] != INT_MAX) {
                    int current = cnt_a - cnt_b - best[right_status ^ 0b10];
                    if (current > ans) {
                        ans = current;
                    }
                }
            }
        }
    }

    return ans;
}