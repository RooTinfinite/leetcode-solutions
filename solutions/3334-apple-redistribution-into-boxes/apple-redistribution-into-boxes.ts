function minimumBoxes(apple: number[], capacity: number[]): number {
    let sum = apple.reduce((a, b) => a + b, 0);

    capacity.sort((a, b) => b - a);

    let need = 0;
    while (sum > 0) {
        sum -= capacity[need];
        need += 1;
    }

    return need;
}