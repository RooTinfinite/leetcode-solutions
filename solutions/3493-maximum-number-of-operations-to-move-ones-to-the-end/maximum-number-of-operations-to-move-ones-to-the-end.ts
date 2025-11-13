function maxOperations(s: string): number {
    let countOne: number = 0;
    let ans: number = 0;
    let i: number = 0;
    while (i < s.length) {
        if (s[i] === "0") {
            while (i + 1 < s.length && s[i + 1] === "0") {
                i++;
            }
            ans += countOne;
        } else {
            countOne++;
        }
        i++;
    }
    return ans;
}