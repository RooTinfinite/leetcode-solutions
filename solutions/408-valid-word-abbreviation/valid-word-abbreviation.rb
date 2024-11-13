def valid_word_abbreviation(word, abbr)
    i = j = 0
   
    while i < word.length && j < abbr.length
        if abbr[j] =~ /\d/
            return false if abbr[j] == '0'
            num = 0
            while j < abbr.length && abbr[j] =~ /\d/
                num = num * 10 + abbr[j].to_i
                j += 1
            end
            i += num
        else
            return false if word[i] != abbr[j]
            i += 1
            j += 1
        end
    end
   
    i == word.length && j == abbr.length
end


