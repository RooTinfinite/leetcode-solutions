class Solution:
    def canMakeSubsequence(self, source: str, target: str) -> bool:
        src_len, tgt_len = len(source), len(target)
        target_char = target[0]
        
        src_idx = tgt_idx = 0
        while src_idx < src_len and tgt_idx < tgt_len:
            src_char = source[src_idx]
            
            if (src_char == target_char or 
                chr(ord(src_char) + 1) == target_char or 
                (src_char == 'z' and target_char == 'a')):
                tgt_idx += 1
                if tgt_idx < tgt_len:
                    target_char = target[tgt_idx]
            
            src_idx += 1
            
        return tgt_idx == tgt_len