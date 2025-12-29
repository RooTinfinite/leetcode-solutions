function dietPlanPerformance(
    calories: number[],
    k: number,
    lower: number,
    upper: number,
): number {
    let score = 0;
    let sum = 0;
    for (let i = 0; i < k; i++) {
        sum += calories[i];
    }
    for (let i = k; i < calories.length; i++) {
        if (sum < lower) {
            score--;
        } else if (sum > upper) {
            score++;
        }
        sum += calories[i] - calories[i - k];
    }
    if (sum < lower) {
        score--;
    } else if (sum > upper) {
        score++;
    }
    return score;
}