class Solution:
    def canBeTypedWords(self, text: str, brokenLetters: str) -> int:
        words = text.split(" ")
        cnt = len(words)
        for word in words:
            for letter in brokenLetters:
                if letter in word:
                    cnt -= 1
                    break
        return cnt