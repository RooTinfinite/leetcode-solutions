class Solution(object):
    def processStr(self, s):
        """
        :type s: str
        :rtype: str
        """
        result = []

        for c in s:
            if c == '*':
                if result:
                    result.pop()
            elif c == '#':
                result += result[:]
            elif c == '%':
                result.reverse()
            else:
                result.append(c)

        return ''.join(result)