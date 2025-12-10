function candy(ratings: number[]): number {
    let sum = 0;
    const len = ratings.length;
    const left2right = new Array(len).fill(1);
    const right2left = new Array(len).fill(1);
    for (let i = 1; i < len; i++) {
        if (ratings[i] > ratings[i - 1]) {
            left2right[i] = left2right[i - 1] + 1;
        }
    }
    for (let i = len - 2; i >= 0; i--) {
        if (ratings[i] > ratings[i + 1]) {
            right2left[i] = right2left[i + 1] + 1;
        }
    }
    for (let i = 0; i < len; i++) {
        sum += Math.max(left2right[i], right2left[i]);
    }
    return sum;
}