function makeFancyString(s) {
    // Convert string to array since strings are immutable in JavaScript
    let chars = s.split('');
    
    // Return original string if length is less than 3
    if (chars.length < 3) {
        return s;
    }
    
    // j keeps track of the position where we'll place
    // the next valid character
    let j = 2;
    
    // Iterate through string starting from index 2
    for (let i = 2; i < chars.length; i++) {
        // Add current character if it's different from
        // either of the two previous characters
        if (chars[i] !== chars[j - 1] || chars[i] !== chars[j - 2]) {
            chars[j++] = chars[i];
        }
    }
    
    // Return the fancy string by joining the array
    // and slicing to the correct length
    return chars.slice(0, j).join('');
}