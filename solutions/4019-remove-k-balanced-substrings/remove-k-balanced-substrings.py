class Solution:
    def removeSubstring(self, s: str, k: int) -> str:
        open_counts = []
        close_counts = []
        current_open = 0
        current_close = 0
        char_stack = []

        for char in s:
            char_stack.append(char)

            if char == '(':
                if current_close != 0:
                    close_counts.append(current_close)
                    open_counts.append(current_open)
                    current_close = 0
                    current_open = 1
                else:
                    current_open += 1
            elif char == ')':
                current_close += 1

            while True:
                if current_close == k and current_open > k:
                    for _ in range(2 * k):
                        char_stack.pop()
                    current_open -= k
                    current_close -= k
                elif current_close == k and current_open == k:
                    for _ in range(2 * k):
                        char_stack.pop()
                    current_open -= k
                    current_close -= k
                    if char_stack:
                        last_char = char_stack[-1]
                        if last_char == '(':
                            current_open = open_counts.pop()
                        else:
                            current_open = open_counts.pop()
                            current_close = close_counts.pop()
                else:
                    break

        return ''.join(char_stack)