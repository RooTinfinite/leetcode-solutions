class Solution {
    // Map to store digit-to-letters mapping
    private Map<Character, String> phoneMap = Map.of(
        '2', "abc",
        '3', "def",
        '4', "ghi",
        '5', "jkl",
        '6', "mno",
        '7', "pqrs",
        '8', "tuv",
        '9', "wxyz"
    );
    
    // List to store all combinations
    private List<String> output = new ArrayList<>();
    
    private void backtrack(String combination, String nextDigits) {
        // Base case: if no more digits to process
        if (nextDigits.length() == 0) {
            output.add(combination);
        } else {
            // Get letters for current digit
            String letters = phoneMap.get(nextDigits.charAt(0));
            
            // Try each letter for current digit
            for (char letter : letters.toCharArray()) {
                // Recursively process remaining digits
                backtrack(combination + letter, nextDigits.substring(1));
            }
        }
    }
    
    public List<String> letterCombinations(String digits) {
        // Handle empty input
        if (digits.length() == 0) {
            return new ArrayList<>();
        }
        
        // Clear output for fresh calculation
        output.clear();
        
        // Start backtracking process
        backtrack("", digits);
        
        return output;
    }
}