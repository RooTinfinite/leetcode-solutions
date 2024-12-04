def can_make_subsequence(source, target)
    target_idx = 0
    target_len = target.length
    
    source.each_char do |curr_char|
        if target_idx < target_len && (target[target_idx].ord - curr_char.ord) % 26 <= 1
            target_idx += 1
        end
    end
    
    target_idx == target_len
end