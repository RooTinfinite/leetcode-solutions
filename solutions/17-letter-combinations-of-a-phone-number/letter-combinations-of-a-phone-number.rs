impl Solution {
    pub fn letter_combinations(digits: String) -> Vec<String> {
        // Return early if input is empty
        if digits.is_empty() {
            return vec![];
        }
        
        // Create phone mapping using a HashMap
        let phone_map: std::collections::HashMap<char, &str> = [
            ('2', "abc"),
            ('3', "def"),
            ('4', "ghi"),
            ('5', "jkl"),
            ('6', "mno"),
            ('7', "pqrs"),
            ('8', "tuv"),
            ('9', "wxyz"),
        ].iter().cloned().collect();
        
        let mut output: Vec<String> = Vec::new();
        
        // Helper function for backtracking
        fn backtrack(
            combination: String,
            next_digits: &str,
            phone_map: &std::collections::HashMap<char, &str>,
            output: &mut Vec<String>
        ) {
            // Base case: if no more digits to check
            if next_digits.is_empty() {
                output.push(combination);
                return;
            }
            
            // Get current digit and its corresponding letters
            if let Some(&letters) = phone_map.get(&next_digits.chars().next().unwrap()) {
                // For each letter corresponding to current digit
                for letter in letters.chars() {
                    // Create new combination and process remaining digits
                    let mut new_combination = combination.clone();
                    new_combination.push(letter);
                    backtrack(
                        new_combination,
                        &next_digits[1..],
                        phone_map,
                        output
                    );
                }
            }
        }
        
        // Start backtracking with empty combination
        backtrack(String::new(), &digits, &phone_map, &mut output);
        
        output
    }
}