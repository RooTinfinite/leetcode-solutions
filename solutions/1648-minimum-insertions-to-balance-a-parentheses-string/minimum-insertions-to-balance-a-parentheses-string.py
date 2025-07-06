class Solution:
    def minInsertions(self, s: str) -> int:
        open_counts = 0
        insertions = 0

        i = 0
        while i < len(s):
            if s[i] == '(':
                open_counts += 1
            elif i + 1 < len(s) and s[i + 1] == ')':
                if open_counts > 0:
                    open_counts -= 1
                else:
                    insertions += 1
                i += 1  # Skip the next ')'
            else:
                if open_counts > 0:
                    open_counts -= 1
                    insertions += 1
                else:
                    insertions += 2
            i += 1

        return insertions + 2 * open_counts