class Solution {
    public boolean canRemoveAll(int[] types, int[] colors, int[] groupSize) {
        int n = types.length;
        int[] t = new int[n];
        int[] c = new int[n];
        int[] count = new int[n];
        int top = -1;
        for (int i = 0; i < n; i++) {
            if (top >= 0 && t[top] == types[i] && c[top] == colors[i]) {
                count[top]++;
            } else {
                top++;
                t[top] = types[i];
                c[top] = colors[i];
                count[top] = 1;
            }
            if (count[top] == groupSize[types[i]]) {
                top--;
            }
        }
        return top == -1;
    }
}