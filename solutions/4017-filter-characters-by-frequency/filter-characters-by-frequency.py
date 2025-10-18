class Solution:
    def filterCharacters(self, s: str, k: int) -> str:

        counter = Counter(s)
        result = []

        for letter in s:
            if counter[letter] < k:
                result.append(letter)

        return "".join(result)