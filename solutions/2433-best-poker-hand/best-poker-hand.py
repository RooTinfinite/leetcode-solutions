from collections import Counter

class Solution:
    def bestHand(self, ranks: list[int], suits: list[str]) -> str:
        if len(set(suits)) == 1:
            return "Flush"
        m = max(Counter(ranks).values())
        if m >= 3:
            return "Three of a Kind"
        if m == 2:
            return "Pair"
        return "High Card"