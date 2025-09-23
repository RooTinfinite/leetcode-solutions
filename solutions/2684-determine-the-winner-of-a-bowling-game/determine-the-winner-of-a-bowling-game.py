class Solution:
    def isWinner(self, player_1_scores, player_2_scores):
        len_player_1_scores = len(player_1_scores)
        len_player_2_scores = len(player_2_scores)
        sum_player_1_scores = 0
        sum_player_2_scores = 0
        i = 0
        while (i < len_player_1_scores):
            sum_player_1_scores += 2 * player_1_scores[i] if (i >= 1 and player_1_scores[i-1] == 10) or (i >= 2 and player_1_scores[i-2] == 10) else player_1_scores[i]
            sum_player_2_scores += 2 * player_2_scores[i] if (i >= 1 and player_2_scores[i-1] == 10) or (i >= 2 and player_2_scores[i-2] == 10) else player_2_scores[i]
            i += 1

        if (sum_player_1_scores == sum_player_2_scores):
            return 0
        elif (sum_player_1_scores > sum_player_2_scores):
            return 1
        elif (sum_player_1_scores < sum_player_2_scores):
            return 2