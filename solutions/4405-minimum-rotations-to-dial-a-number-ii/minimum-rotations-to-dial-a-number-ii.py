class Solution:
    def minRotations(self, n: int, s: str) -> int:
        dist = lambda a, b: min((int(a) - int(b)) % 10, (int(b) - int(a)) % 10)
        pairs = list(pairwise("0" + s))  # every step of the dial
        base = sum(dist(a, b) for a, b in pairs)
        gain = max(dist(a, b) - dist(a, s[-1]) for a, b in pairs)
        return base - gain