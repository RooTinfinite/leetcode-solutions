class Solution(object):
    def scoreOfParentheses(self, s):
        """
        :type s: str
        :rtype: int
        """

        stack = []

        for i in range(len(s)):
            if s[i] == "(":
                stack.append(s[i])
            else:
                # as it is balanced you will have a ( in the stack so pop it
                sum_var = 0
                while True:
                    val = stack.pop()
                    # add the numeric values
                    if type(val) in (int, float):
                        sum_var = sum_var + val
                    # otherwise you have reached a (
                    else:
                        # handling the nested case using a condition statement here
                        stack.append(sum_var * 2 if sum_var > 0 else 1)
                        break
        sum_var = 0
        while stack:
            sum_var += stack.pop()

        return sum_var