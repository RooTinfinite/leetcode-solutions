function minimumDeletions(s: string): number {
    let count = 0;
    let res = 0;

    for (let i = 0; i < s.length; i++) {
        if (s[i] === 'a') {
            res = Math.min(count, 1 + res);
        } else {
            count++;
        }
    }

    return res;
};