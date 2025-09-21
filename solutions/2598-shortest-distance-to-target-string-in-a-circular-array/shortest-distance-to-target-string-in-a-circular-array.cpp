class Solution { 
public:
    int closestTarget(vector<string>& W, string T, int s) {
        int a = INT_MAX, n = W.size();
        for (int i = 0; i < n; i++) {
            if (W[i] == T) {
                int d = abs(i - s);
                a = min(a, min(d, n - d));
            }
        }
        return a == INT_MAX ? -1 : a;
    }
};