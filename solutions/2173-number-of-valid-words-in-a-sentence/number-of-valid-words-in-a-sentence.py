class Solution:
    def countValidWords(self, sentence: str) -> int:
        count = 0
        for word in sentence.split():
            valid = True
            hypen = 0
            for i,w in enumerate(word):
                if w.islower():
                    continue
                if w.isdigit():
                    valid = False
                    break
                if w == '-':
                    hypen += 1
                    if hypen > 1:
                        valid = False
                        break
                    elif i == 0 or i == len(word) - 1:
                        valid = False
                        break
                    elif not word[i-1].islower() or not word[i+1].islower():
                        valid = False
                        break
                if w in '!,.':
                    if i != len(word)-1:
                        valid = False
                        break
            count+=valid
        return count
                    
                