function isValid(word: string): boolean {
    if (word.length < 3) {
        return false;
    }
    let hasVowel = false;
    let hasConsonant = false;
    for (const c of word) {
        if (/[a-zA-Z]/.test(c)) {
            const ch = c.toLowerCase();
            if (
                ch === "a" ||
                ch === "e" ||
                ch === "i" ||
                ch === "o" ||
                ch === "u"
            ) {
                hasVowel = true;
            } else {
                hasConsonant = true;
            }
        } else if (!/\d/.test(c)) {
            return false;
        }
    }
    return hasVowel && hasConsonant;
}