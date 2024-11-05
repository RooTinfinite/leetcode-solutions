class Solution:
    def isValid(self, s: str) -> bool:
        stack =[]
        CloseToOpen = { ")":"(", "}":"{", "]":"[" }
        
        for c in s:
            if c in CloseToOpen: # check if its a closing paranthesis
                if stack and stack[-1] == CloseToOpen[c]:
                    stack.pop()
                else:
                    return False

            else:
                stack.append(c)
        return stack == []
       
        