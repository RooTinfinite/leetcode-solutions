class Solution:
    def canMakeSubsequence(self, source: str, target: str) -> bool:
        s_len, t_len = len(source), len(target)
        curr_t = target[0]
        
        s_pos = t_pos = 0
        
        while s_pos < s_len and t_pos < t_len:
            curr_s = source[s_pos]
            
            if (curr_s == curr_t or 
                chr(ord(curr_s) + 1) == curr_t or 
                (curr_s == 'z' and curr_t == 'a')):
                t_pos += 1
                if t_pos < t_len:
                    curr_t = target[t_pos]
            
            s_pos += 1
            
        return t_pos == t_len