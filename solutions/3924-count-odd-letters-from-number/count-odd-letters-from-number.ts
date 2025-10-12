function countOddLetters(input: number): number {
    const frequency = createFrequency(input);
    let numberOfOddLetters = 0;
    for (let current of frequency) {
        if (isOdd(current)) {
            ++numberOfOddLetters;
        }
    }
    return numberOfOddLetters;
};

class Util {
    static ALPHABET_SIZE = 26;
    static ASCII_SMALL_CASE_A = 97;
    static DIGIT_TO_WORD =
        ["zero", "one", "two", "three", "four",
         "five", "six", "seven", "eight", "nine"];

}

function createFrequency(input: number): number[] {
    const frequency = new Array(Util.ALPHABET_SIZE).fill(0);
    while (input > 0) {
        const digit = input % 10;
        for (let i = 0; i < Util.DIGIT_TO_WORD[digit].length; ++i) {
            ++frequency[Util.DIGIT_TO_WORD[digit].codePointAt(i) - Util.ASCII_SMALL_CASE_A];
        }
        input = Math.floor(input / 10);
    }
    return frequency;
}

function isOdd(value: number): boolean {
    return value % 2 === 1;
}