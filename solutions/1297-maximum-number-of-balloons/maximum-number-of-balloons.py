class Solution:
    def maxNumberOfBalloons(self, text: str) -> int:
        freq=Counter(text)
        m,m1=min(freq['b'],freq['a'],freq['n']),min(freq['l'],freq['o'])
        return m if m1>=m*2 else m1//2      