class Solution:
    def reformat(self, s: str) -> str:
        digits = []
        letters = []
        for char in s:
            if char.isdigit():
                digits.append(char)
            else:
                letters.append(char)
        if len(digits) - len(letters) not in {-1, 0, 1}:
            return ""
        ans = ""
        if len(digits) >= len(letters):
            while digits:
                ans += digits.pop()
                try:
                    ans += letters.pop()
                except:
                    continue
        else:
            while letters:
                ans += letters.pop()
                try:
                    ans += digits.pop()
                except:
                    continue
        return ans