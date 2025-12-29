class Solution {
public:
    int dietPlanPerformance(vector<int>& calories, int k, int lower,
                            int upper) {
        int sum = 0, score = 0;
        for (int i = 0; i < k; i++) {
            sum += calories[i];
        }
        for (int i = k; i < calories.size(); i++) {
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
};