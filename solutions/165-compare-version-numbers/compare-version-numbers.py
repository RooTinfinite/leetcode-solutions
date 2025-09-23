class Solution:
    def get_next_chunk(self, version: str, n: int, p: int) -> List[int]:
        # If pointer is set to the end of the string, return 0
        if p > n - 1:
            return 0, p

        # Find the end of the chunk
        p_end = p
        while p_end < n and version[p_end] != ".":
            p_end += 1

        # Retrieve the chunk
        i = int(version[p:p_end]) if p_end != n - 1 else int(version[p:n])

        # Find the beginning of the next chunk
        p = p_end + 1

        return i, p

    def compareVersion(self, version1: str, version2: str) -> int:
        p1 = p2 = 0
        n1, n2 = len(version1), len(version2)

        # Compare versions
        while p1 < n1 or p2 < n2:
            i1, p1 = self.get_next_chunk(version1, n1, p1)
            i2, p2 = self.get_next_chunk(version2, n2, p2)
            if i1 != i2:
                return 1 if i1 > i2 else -1

        # The versions are equal
        return 0