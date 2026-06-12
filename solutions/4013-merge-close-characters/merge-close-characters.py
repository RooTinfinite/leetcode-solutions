class Solution:
    def mergeCharacters(self, s: str, k: int) -> str:
        result = []
        lastk = Counter()
        for char in s:
            if lastk[char] > 0:  # Merge = skip the character
                continue

            # Add new character to the last k
            result.append(char)
            lastk[char] += 1
            if len(result) > k: # If there were already k, remove the first one
                drop = result[-k - 1]  # The first char, we should remove it
                lastk[drop] -= 1

        return "".join(result)