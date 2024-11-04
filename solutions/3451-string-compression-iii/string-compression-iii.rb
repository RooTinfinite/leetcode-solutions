def compressed_string(word)
    # Handle empty string case - return empty string if input is empty
    return "" if word.empty?
    
    # Initialize result string to store compressed output
    comp = ""
    
    # Initialize counter to track consecutive character occurrences
    cnt = 1
    
    # Initialize first character to process
    ch = word[0]
    
    # Iterate through string starting from second character
    (1...word.length).each do |i|
        # If current character matches previous and count less than 9
        # increment counter
        if word[i] == ch && cnt < 9
            cnt += 1
        # If character changes or count reaches 9
        # append count and character to result
        else
            comp << cnt.to_s << ch    # Convert count to string and append with character
            ch = word[i]              # Update current character being tracked
            cnt = 1                   # Reset counter for new character
        end
    end
    
    # Handle the last group of characters
    comp << cnt.to_s << ch    # Append final count and character
    
    # Return compressed string
    comp
end