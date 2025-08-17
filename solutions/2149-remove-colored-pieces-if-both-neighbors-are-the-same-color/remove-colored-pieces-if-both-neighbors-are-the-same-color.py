class Solution:
    def winnerOfGame(self, colors: str) -> bool:
        alice_score = 0
        bob_score = 0

        # Iterate through the colors, excluding the edge pieces
        for i in range(1, len(colors) - 1):
            current_color = colors[i]
            prev_color = colors[i - 1]
            next_color = colors[i + 1]

            # Check if Alice can make a move here
            if current_color == 'A' and prev_color == 'A' and next_color == 'A':
                alice_score += 1  # Alice can remove 'A'

            # Check if Bob can make a move here
            elif current_color == 'B' and prev_color == 'B' and next_color == 'B':
                bob_score += 1  # Bob can remove 'B'

        # Determine the winner based on the scores
        return alice_score > bob_score