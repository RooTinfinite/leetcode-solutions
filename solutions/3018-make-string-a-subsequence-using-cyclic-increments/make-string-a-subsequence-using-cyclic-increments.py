class Solution:
    def canMakeSubsequence(self, source: str, target: str) -> bool:
        source_len, target_len = len(source), len(target)
        curr_target = target[0]
        
        source_pos = target_pos = 0
        
        while source_pos < source_len and target_pos < target_len:
            curr_char = source[source_pos]
            
            if (curr_char == curr_target or 
                chr(ord(curr_char) + 1) == curr_target or 
                (curr_char == 'z' and curr_target == 'a')):
                target_pos += 1
                if target_pos < target_len:
                    curr_target = target[target_pos]
            
            source_pos += 1
            
        return target_pos == target_len