class Solution:
    def partition(self, s: str) -> List[List[str]]:
        len_s = len(s)
        dp = [[False] * len_s for _ in range(len_s)]
        result = []
        self.dfs(result, s, 0, [], dp)
        return result

    def dfs(
        self,
        result: List[List[str]],
        s: str,
        start: int,
        currentList: List[str],
        dp: List[List[bool]],
    ):
        if start >= len(s):
            result.append(list(currentList))
        for end in range(start, len(s)):
            if s[start] == s[end] and (
                end - start <= 2 or dp[start + 1][end - 1]
            ):
                dp[start][end] = True
                currentList.append(s[start : end + 1])
                self.dfs(result, s, end + 1, currentList, dp)
                currentList.pop()