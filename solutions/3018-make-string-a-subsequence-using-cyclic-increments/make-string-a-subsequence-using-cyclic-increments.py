class Solution:
    def canMakeSubsequence(self, source: str, target: str) -> bool:
        src_len = len(source)
        tgt_len = len(target)
        src_idx = 0
        tgt_idx = 0
        
        while src_idx < src_len and tgt_idx < tgt_len:
            if (source[src_idx] == target[tgt_idx] or 
                (source[src_idx] == 'z' and target[tgt_idx] == 'a') or 
                (ord(source[src_idx]) + 1 == ord(target[tgt_idx]))):
                src_idx += 1
                tgt_idx += 1
            else:
                src_idx += 1
                
        return tgt_idx == tgt_len