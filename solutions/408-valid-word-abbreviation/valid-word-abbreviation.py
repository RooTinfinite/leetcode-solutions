class Solution:
    def validWordAbbreviation(self, word: str, abbreviation: str) -> bool:
        word_pos = abbr_pos = 0
       
        while abbr_pos < len(abbreviation) and word_pos < len(word):
            if abbreviation[abbr_pos].isalpha():
                if abbreviation[abbr_pos] != word[word_pos]:
                    return False
                word_pos += 1
                abbr_pos += 1
            else:
                # Handle numeric abbreviation
                if abbreviation[abbr_pos] == '0':
                    return False
                   
                skip_count = self._parse_number(abbreviation, abbr_pos)
                abbr_pos += len(str(skip_count))
                word_pos += skip_count
               
        return abbr_pos == len(abbreviation) and word_pos == len(word)
   
    def _parse_number(self, abbreviation: str, start_pos: int) -> int:
        """Extract number from abbreviation starting at given position."""
        number = 0
        while (start_pos < len(abbreviation) and
               abbreviation[start_pos].isdigit()):
            number = number * 10 + int(abbreviation[start_pos])
            start_pos += 1
        return number