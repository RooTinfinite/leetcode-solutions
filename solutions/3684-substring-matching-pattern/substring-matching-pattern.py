class Solution:
    def hasMatch(self, s: str, p: str) -> bool:

        head, tail = p.split('*')                   # <-- 1)

        left, rght = s.find(head), s.rfind(tail)    # <-- 2)
        if left == -1 or rght == -1: return False

        return left + len(head) <= rght             # <-- 3)