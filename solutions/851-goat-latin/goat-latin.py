class Solution:
    def toGoatLatin(self, sentence: str) -> str:
        vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
        new_sentence = sentence.split()
        for i in range(len(new_sentence)):
            if new_sentence[i][0] in vowels:
                new_sentence[i] = new_sentence[i] + "ma" + "a"*(i+1)
            else:
                new_sentence[i] = new_sentence[i][1:] + new_sentence[i][0] + "ma" + "a"*(i+1)


        return " ".join(new_sentence)
        