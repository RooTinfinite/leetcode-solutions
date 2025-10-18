class Solution {
    public String filterCharacters(String s, int k) {
        
        HashMap<Character, Integer> counter = new HashMap<>();

        // 1. Make frequency counter of s
        for(int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            counter.put(letter, counter.getOrDefault(letter, 0) + 1);
        }

        // 2. Construct the result
        StringBuilder result = new StringBuilder();

        for(int i = 0; i < s.length(); i++) {
            char letter = s.charAt(i);
            if(counter.get(letter) < k) {
                result.append(letter);
            }
        }

        return result.toString();
    }
}