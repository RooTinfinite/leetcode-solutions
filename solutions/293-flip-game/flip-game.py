class Solution:
    def generatePossibleNextMoves(self, currentState: str) -> List[str]:
        string_list = list(currentState)
        res = []
        for i in range(1, len(currentState)):
            if currentState[i - 1] == '+' and currentState[i] == '+':
                string_list[i - 1], string_list[i] = '-', '-'
                res.append(''.join(string_list))
                string_list = list(currentState)
        return res