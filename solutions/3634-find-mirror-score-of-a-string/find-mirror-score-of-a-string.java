
import java.util.*;

class Solution {
    public long calculateScore(String str) {
        Map<Character, Character> revMap = new HashMap<>();
        for (char c = 'a'; c <= 'z'; ++c) {
            revMap.put(c, (char) ('z' - (c - 'a')));
        }

        long total = 0;
        Stack<Integer>[] stacks = new Stack[26];
        for (int i = 0; i < 26; i++) {
            stacks[i] = new Stack<>();
        }

        for (int idx = 0; idx < str.length(); ++idx) {
            char curr = str.charAt(idx);
            char mirror = revMap.get(curr);

            if (!stacks[mirror - 'a'].isEmpty()) {
                int prevIdx = stacks[mirror - 'a'].pop();
                total += idx - prevIdx;
            } else {
                stacks[curr - 'a'].push(idx);
            }
        }

        return total;
    }
}