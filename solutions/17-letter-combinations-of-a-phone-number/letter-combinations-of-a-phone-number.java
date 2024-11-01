class Solution {
    private Map<Character, String> phoneMap;
    private List<String> output;
    
    public List<String> letterCombinations(String digits) {
        // Initialize output list and return empty list if input is empty
        output = new ArrayList<>();
        if (digits.length() == 0) {
            return output;
        }
        
        // Initialize phone mapping
        phoneMap = new HashMap<>();
        phoneMap.put('2', "abc");
        phoneMap.put('3', "def");
        phoneMap.put('4', "ghi");
        phoneMap.put('5', "jkl");
        phoneMap.put('6', "mno");
        phoneMap.put('7', "pqrs");
        phoneMap.put('8', "tuv");
        phoneMap.put('9', "wxyz");
        
        // Start backtracking
        backtrack("", digits);
        return output;
    }
    
    private void backtrack(String combination, String nextDigits) {
        // Base case: if no more digits to check
        if (nextDigits.length() == 0) {
            output.add(combination);
        } else {
            // Get the first digit and its corresponding letters
            String letters = phoneMap.get(nextDigits.charAt(0));
            
            // For each letter corresponding to current digit
            for (char letter : letters.toCharArray()) {
                // Add current letter to combination and process remaining digits
                backtrack(combination + letter, nextDigits.substring(1));
            }
        }
    }
}