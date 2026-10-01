class Solution:
    def edgeScore(self, edges: list[int]) -> int:
        score = defaultdict(int)

        for u, v in enumerate(edges):
            score[v] += u

        return max(score, key=lambda x: (score[x], -x))