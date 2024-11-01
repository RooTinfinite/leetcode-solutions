function letterCombinations(digits: string): string[] {
    if (!digits) {
        return [];
    }

    const phoneMap: Record<string, string> = {
        '2': 'abc',
        '3': 'def',
        '4': 'ghi',
        '5': 'jkl',
        '6': 'mno',
        '7': 'pqrs',
        '8': 'tuv',
        '9': 'wxyz'
    };

    const output: string[] = [];

    function backtrack(combination: string, nextDigits: string): void {
        if (nextDigits.length === 0) {
            output.push(combination);
        } else {
            for (const letter of phoneMap[nextDigits[0]]) {
                backtrack(combination + letter, nextDigits.slice(1));
            }
        }
    }

    backtrack("", digits);
    return output;
}