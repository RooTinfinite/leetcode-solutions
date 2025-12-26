func bestClosingTime(customers string) int {
    max_score, score, best_hour := 0, 0, -1
    for i := 0; i < len(customers); i++ {
        if customers[i] == 'Y' {
            score++
        } else {
            score--
        }
        if score > max_score {
            max_score = score
            best_hour = i
        }
    }
    return best_hour + 1
}