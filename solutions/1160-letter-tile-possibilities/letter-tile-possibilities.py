class Solution:
    def numTilePossibilities(self, tiles: str) -> int:
        sequences = set()
        used = [False] * len(tiles)

        # Generate all possible sequences including empty string
        self._generate_sequences(tiles, "", used, sequences)

        # Subtract 1 to exclude empty string from count
        return len(sequences) - 1

    def _generate_sequences(
        self, tiles: str, current: str, used: list, sequences: set
    ) -> None:
        sequences.add(current)

        # Try adding each unused character to current sequence
        for pos, char in enumerate(tiles):
            if not used[pos]:
                used[pos] = True
                self._generate_sequences(tiles, current + char, used, sequences)
                used[pos] = False