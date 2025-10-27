function convert(s: string, numRows: number): string {
    if (numRows === 1) {
        return s;
    }

    let answer: string = "";
    let n: number = s.length;
    let charsInSection: number = 2 * (numRows - 1);

    for (let currRow: number = 0; currRow < numRows; ++currRow) {
        let index: number = currRow;
        while (index < n) {
            answer += s[index];

            // If current row is not first or last,
            // then we have to add one more character of current section.
            if (currRow != 0 && currRow != numRows - 1) {
                let charsInBetween: number = charsInSection - 2 * currRow;
                let secondIndex: number = index + charsInBetween;
                if (secondIndex < n) {
                    answer += s[secondIndex];
                }
            }
            // Jump to same row's first character of next section.
            index += charsInSection;
        }
    }
    return answer;
}