public class Solution {
    public String findValidPair(String s) {

        Map<Character, Integer> ctr = new HashMap<>();
        for (char c : s.toCharArray()) {
            ctr.put(c, ctr.getOrDefault(c, 0) + 1);}

        Set<Character> valid = new HashSet<>();
        for (Map.Entry<Character, Integer> entry : ctr.entrySet()) {
            char digit = entry.getKey();
            int count = entry.getValue();
            if (count == digit - '0') {
                valid.add(digit); }}

        for (int i = 0; i < s.length() - 1; i++) {
            char digit1 = s.charAt(i);
            char digit2 = s.charAt(i + 1);
            if (digit1 == digit2) continue; 
            if (valid.contains(digit1) && valid.contains(digit2)) {
                return "" + digit1 + digit2;}}
        
        return ""; } }