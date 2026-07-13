const q = [1, 2, 3, 4, 5, 6, 7, 8, 9];

for (const c of q) {
    const d = c % 10;
    if (d < 9) q.push(c * 10 + d + 1);
}

const sequentialDigits = (low, high) =>
    q.filter(c => c >= low && c <= high);