var minInsertions = function(s) {
    let openCounts = 0; // Tracks unmatched '('
    let insertions = 0; // Tracks required insertions

    for (let i = 0; i < s.length; i++) {
        if (s[i] === '(') {
            openCounts++;
        } else if (i + 1 < s.length && s[i + 1] === ')') {
            if (openCounts > 0) openCounts--;
            else insertions++;
            i++; // Skip the next ')'
        } else {
            if (openCounts > 0) {
                openCounts--;
                insertions++;
            } else {
                insertions += 2;
            }
        }
    }

    return insertions + 2 * openCounts;
};