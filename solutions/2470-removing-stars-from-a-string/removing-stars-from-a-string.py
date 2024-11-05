class Solution(object):
    def removeStars(self, s):
        stack = []

        # Iterate over each character in the input string
        for c in s:
            # If the current character is a star and the stack is not empty, pop the topmost character
            # from the stack
            if c == '*' and stack:
                stack.pop()
            # Otherwise, push the current character onto the stack
            else:
                stack.append(c)

        # Convert the stack to a string and return it as the output
        return ''.join(stack)