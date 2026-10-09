var minInsertions = function (s) {
    let insertions = 0;
    let leftCount = 0;
    const length = s.length;
    let index = 0;

    while (index < length) {
        const c = s[index];
        if (c === "(") {
            leftCount++;
            index++;
        } else {
            if (leftCount > 0) {
                leftCount--;
            } else {
                insertions++;
            }

            if (index < length - 1 && s[index + 1] === ")") {
                index += 2;
            } else {
                insertions++;
                index++;
            }
        }
    }

    insertions += leftCount * 2;
    return insertions;
};