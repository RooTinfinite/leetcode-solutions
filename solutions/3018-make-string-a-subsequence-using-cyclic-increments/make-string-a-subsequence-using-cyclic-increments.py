class Solution:
    @staticmethod
    def canMakeSubsequence(source: str, target: str) -> bool:
        src_len, tgt_len = len(source), len(target)
        if src_len < tgt_len:
            return False
            
        tgt_idx = 0
        for c in source:
            next_char = chr((ord(c) - ord('a') + 1) % 26 + ord('a'))
            if tgt_idx < tgt_len and (c == target[tgt_idx] or next_char == target[tgt_idx]):
                tgt_idx += 1
                
        return tgt_idx == tgt_len