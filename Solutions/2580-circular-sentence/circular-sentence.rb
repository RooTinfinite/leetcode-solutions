def is_circular_sentence(sentence)
  # Get the length of the sentence
  n = sentence.length
  
  # First check: Compare first and last character of sentence
  return false if sentence[0] != sentence[n-1]
  
  # Iterate through the sentence, starting from index 1 to n-2
  (1..n-2).each do |i|
    # When we find a space character
    if sentence[i] == ' '
      # Check if the character before space matches the character after space
      return false if sentence[i-1] != sentence[i+1]
    end
  end
  
  # If we made it through all checks, the sentence is circular
  true
end