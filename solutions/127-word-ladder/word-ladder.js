var ladderLength = function (beginWord, endWord, wordList) {
    // Since all words are of same length.
    let L = beginWord.length;
    // Dictionary to hold combination of words that can be formed,
    // from any given word. By changing one letter at a time.
    let allComboDict = {};
    for (let word of wordList) {
        for (let i = 0; i < L; i++) {
            // Key is the generic word
            // Value is a list of words which have the same intermediate generic word.
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            if (!allComboDict[newWord]) allComboDict[newWord] = [];
            allComboDict[newWord].push(word);
        }
    }
    // Queue for BFS
    let Q = [[beginWord, 1]];
    // Visited to make sure we don't repeat processing same word.
    let visited = { [beginWord]: true };
    while (Q.length > 0) {
        let node = Q.shift();
        let word = node[0];
        let level = node[1];
        for (let i = 0; i < L; i++) {
            // Intermediate words for current word
            let newWord = word.substring(0, i) + "*" + word.substring(i + 1, L);
            // Next states are all the words which share the same intermediate state.
            for (let adjacentWord of allComboDict[newWord] || []) {
                // If at any point if we find what we are looking for
                // i.e. the end word - we can return with the answer.
                if (adjacentWord === endWord) {
                    return level + 1;
                }
                // Otherwise, add it to the BFS Queue. Also mark it visited
                if (!visited[adjacentWord]) {
                    visited[adjacentWord] = true;
                    Q.push([adjacentWord, level + 1]);
                }
            }
        }
    }
    return 0;
};