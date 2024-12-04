class Solution:
    @staticmethod
    def canMakeSubsequence(source: str, target: str) -> bool:
        src_len, tgt_len = len(source), len(target)
        if src_len < tgt_len:
            return False
        
        tgt_idx = 0
        target_mask = 1 << (ord(target[0]) - ord('a'))
        
        for src_idx in range(src_len):
            if tgt_idx >= tgt_len:
                break
                
            src_mask = 1 << (ord(source[src_idx]) - ord('a'))
            next_mask = 1 << ((ord(source[src_idx]) - ord('a') + 1) % 26)
            
            if (target_mask & (src_mask | next_mask)) != 0:
                tgt_idx += 1
                if tgt_idx < tgt_len:
                    target_mask = 1 << (ord(target[tgt_idx]) - ord('a'))
        
        return tgt_idx == tgt_len