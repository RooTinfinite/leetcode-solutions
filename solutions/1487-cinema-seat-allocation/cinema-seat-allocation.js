var maxNumberOfFamilies = function (n, reservedSeats) {
    const left = 0b11110000;
    const middle = 0b11000011;
    const right = 0b00001111;

    const occupied = new Map();
    for (const seat of reservedSeats) {
        if (seat[1] >= 2 && seat[1] <= 9) {
            const row = seat[0];
            if (!occupied.has(row)) {
                occupied.set(row, 0);
            }
            occupied.set(row, occupied.get(row) | (1 << (seat[1] - 2)));
        }
    }

    let ans = (n - occupied.size) * 2;
    for (const bitmask of occupied.values()) {
        if (
            (bitmask | left) === left ||
            (bitmask | middle) === middle ||
            (bitmask | right) === right
        ) {
            ans++;
        }
    }
    return ans;
};