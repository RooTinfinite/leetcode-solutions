function numOfStrings(patterns: string[], word: string): number {
    const check = (pattern: string, word: string): boolean => {
        const m = pattern.length;
        const n = word.length;

        // generate the prefix array of the pattern
        const pi: number[] = new Array(m).fill(0);
        for (let i = 1, j = 0; i < m; i++) {
            while (j > 0 && pattern[i] !== pattern[j]) {
                j = pi[j - 1];
            }
            if (pattern[i] === pattern[j]) {
                j++;
            }
            pi[i] = j;
        }

        // using prefix arrays for matching
        for (let i = 0, j = 0; i < n; i++) {
            while (j > 0 && word[i] !== pattern[j]) {
                j = pi[j - 1];
            }
            if (word[i] === pattern[j]) {
                j++;
            }
            if (j === m) {
                return true;
            }
        }
        return false;
    };

    let res = 0;
    for (const pattern of patterns) {
        if (check(pattern, word)) {
            res++;
        }
    }
    return res;
}