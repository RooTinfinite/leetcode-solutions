class Solution:
    def countWordOccurrences(self, chunks, queries):

        s = (
            "".join(chunks)
            .replace("--", "  ")
            .replace(" -", "  ")
            .replace("- ", "  ")
            .strip("-")
            .split()
        )

        freq = Counter(s)

        return [freq[q] for q in queries]