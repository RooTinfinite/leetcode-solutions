class Solution {
    private List<Integer> ans = new ArrayList<>();
    private String num;

    public List<Integer> splitIntoFibonacci(String num) {
        this.num = num;
        dfs(0);
        return ans;
    }

    private boolean dfs(int i) {
        if (i == num.length()) {
            return ans.size() >= 3;
        }
        long x = 0;
        for (int j = i; j < num.length(); ++j) {
            if (j > i && num.charAt(i) == '0') {
                break;  // no leading zeroes
            }
            x = x * 10 + num.charAt(j) - '0';
            if (x > Integer.MAX_VALUE) {
                break;
            }
            if (ans.size() >= 2 && x > (long) ans.get(ans.size() - 1) + ans.get(ans.size() - 2)) {
                break;  // pruning if x too large
            }
            if (ans.size() < 2 || x == ans.get(ans.size() - 1) + ans.get(ans.size() - 2)) {
                ans.add((int) x);
                if (dfs(j + 1)) {
                    return true;
                }
                ans.remove(ans.size() - 1);  // backtrack
            }
        }
        return false;
    }
}