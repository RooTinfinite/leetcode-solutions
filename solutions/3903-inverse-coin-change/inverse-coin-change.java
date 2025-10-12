import java.util.*;

class Solution {
    Map<String, Integer> memo;

    public int getWays(List<Integer> al, int amount, int idx) {
        if (amount == 0) return 1;
        if (amount < 0 || idx == al.size()) return 0;

        String key = amount + "," + idx;
        if (memo.containsKey(key)) return memo.get(key);

        int include = getWays(al, amount - al.get(idx), idx); 
        int exclude = getWays(al, amount, idx + 1);

        int result = include + exclude;
        memo.put(key, result);
        return result;
    }

    public List<Integer> findCoins(int[] numWays) {
        List<Integer> al = new ArrayList<>();

        for (int i = 0; i < numWays.length; i++) {
            int amount = i + 1;

            memo = new HashMap<>();
            int ways = getWays(al, amount, 0);

            if (ways < numWays[i]) {
                al.add(amount); 
                memo = new HashMap<>();
                ways = getWays(al, amount, 0);
            }

            if (ways != numWays[i]) {
                return new ArrayList<>();
            }
        }

        return al;
    }
}