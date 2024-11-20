class Solution:
    def takeCharacters(self, s: str, k: int) -> int:
        c = collections.Counter(s)
        if c['a'] < k or c['b'] < k or c['c'] < k:
            return -1
        target_c = target_a = target_b = k
        window_start = 0
        longest_window = 0
        for window_end, letter in enumerate(s):
            c[letter] -= 1
            while c['a'] < target_a or c['b'] < target_b or c['c'] < target_c:
                l = s[window_start]
                c[l] += 1
                window_start += 1
            longest_window = max(longest_window, window_end - window_start + 1)
        return len(s) - longest_window