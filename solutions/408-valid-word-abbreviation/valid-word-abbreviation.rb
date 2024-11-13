def parse_number(abbreviation, start_pos)
    number = 0
    while start_pos < abbreviation.length && abbreviation[start_pos].match?(/\d/)
        number = number * 10 + abbreviation[start_pos].to_i
        start_pos += 1
    end
    number
end

def valid_word_abbreviation(word, abbreviation)
    word_pos = abbr_pos = 0
    
    while abbr_pos < abbreviation.length && word_pos < word.length
        if abbreviation[abbr_pos].match?(/[a-zA-Z]/)
            return false if abbreviation[abbr_pos] != word[word_pos]
            word_pos += 1
            abbr_pos += 1
        else
            return false if abbreviation[abbr_pos] == '0'
            
            skip_count = parse_number(abbreviation, abbr_pos)
            abbr_pos += skip_count.to_s.length
            word_pos += skip_count
        end
    end
    
    abbr_pos == abbreviation.length && word_pos == word.length
end