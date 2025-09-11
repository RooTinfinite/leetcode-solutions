class Solution(object):
    def calculateTax(self, brackets, income):
        """
        :type brackets: List[List[int]]
        :type income: int
        :rtype: float
        """
        prevBracket = 0
        tax = 0
        for bracket, precent in brackets:
            if income >= bracket:
                tax += (precent / float(100)) * (bracket - prevBracket)
            else:
                tax += (precent / float(100)) * (income - prevBracket)
                break
            prevBracket = bracket
        return tax

            

        