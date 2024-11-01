function makeFancyString(s: string): string {
    // Return original string if length is less than 3
    if (s.length < 3) {
        return s;
    }

    // Convert string to array for easier manipulation
    const chars = s.split('');
    let j = 2;

    // Iterate through string starting from index 2
    for (let i = 2; i < chars.length; i++) {
        // Add current character if it's different from
        // either of the two previous characters
        if (chars[i] !== chars[j - 1] || chars[i] !== chars[j - 2]) {
            chars[j++] = chars[i];
        }
    }

    // Return the fancy string by joining the first j characters
    return chars.slice(0, j).join('');
}