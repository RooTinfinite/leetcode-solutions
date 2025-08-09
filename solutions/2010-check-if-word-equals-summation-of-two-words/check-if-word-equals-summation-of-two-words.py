class Solution:
    def isSumEqual(self, first: str, second: str, target: str) -> bool:
        def op(s: str): return "".join(chr(ord(ch) - 49) for ch in s)
        return int(op(first)) + int(op(second)) == int(op(target))