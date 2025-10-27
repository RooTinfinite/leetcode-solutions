function romanToInt(s: string): number {
    const values: Record<string, number> = {
        I: 1,
        V: 5,
        X: 10,
        L: 50,
        C: 100,
        D: 500,
        M: 1000,
    };

    let lastSymbol = s[s.length - 1];
    let lastValue = values[lastSymbol];
    let total = lastValue;

    for (let i = s.length - 2; i >= 0; i--) {
        let currentSymbol = s[i];
        let currentValue = values[currentSymbol];
        if (currentValue < lastValue) {
            total -= currentValue;
        } else {
            total += currentValue;
        }
        lastValue = currentValue;
    }
    return total;
}