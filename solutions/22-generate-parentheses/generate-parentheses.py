class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n == 0:
            return [""]

        answer = []
        for left_count in range(n):
            left_strings = self.generateParenthesis(left_count)
            right_strings = self.generateParenthesis(n - 1 - left_count)
            for left_string in left_strings:
                for right_string in right_strings:
                    answer.append("(" + left_string + ")" + right_string)

        return answer