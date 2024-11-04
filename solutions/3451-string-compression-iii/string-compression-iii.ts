function compressedString(word: string): string {
    // Initialize empty result string
    let comp: string = "";
    
    // Get total length of input string
    let n: number = word.length;
    
    // Iterate through string with variable increment
    for(let i: number = 0; i < n; ) {
        // Get current character to count
        let char: string = word[i];
        
        // Set maximum look-ahead limit to i + 9 
        // This ensures we never count more than 9 consecutive chars
        let k: number = i + 9;
        
        // Initialize counter for current character sequence
        let length: number = 0;
        
        // Count consecutive occurrences of current char
        // Stop if: reached end of string OR hit max count of 9 OR different char found
        while(i < n && i < k && word[i] === char) {
            length += 1;
            i += 1;
        }
        
        // Add the count and character to result string
        comp += length.toString() + char;
    }
    
    return comp;
}

