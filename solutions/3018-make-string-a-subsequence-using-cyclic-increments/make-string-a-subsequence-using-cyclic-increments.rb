def can_make_subsequence(source, target)
    src_len = source.length
    tgt_len = target.length
    target_char = target[0]
    
    src_idx = 0
    tgt_idx = 0
    
    while src_idx < src_len && tgt_idx < tgt_len
        src_char = source[src_idx]
        
        if src_char == target_char || 
           src_char.next[0] == target_char || 
           (src_char == 'z' && target_char == 'a')
            tgt_idx += 1
            target_char = target[tgt_idx] if tgt_idx < tgt_len
        end
        
        src_idx += 1
    end
    
    tgt_idx == tgt_len
end