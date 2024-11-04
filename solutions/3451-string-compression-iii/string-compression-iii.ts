function compressedString(word: string): string {
    let ans = "";
    let prev = word[0];
    let count = 1;

    for (let i = 1; i < word.length; i++) {
        if (word[i] !== prev) {
            ans += count.toString() + prev;
            prev = word[i];
            count = 1;
        } else {
            if (count === 9) {
                ans += count.toString() + prev;
                count = 1;
            } else {
                count++;
            }
        }
    }

    // Append the last group
    ans += count.toString() + prev;
    return ans;
}