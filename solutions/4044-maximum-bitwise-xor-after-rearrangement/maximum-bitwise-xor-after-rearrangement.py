class Solution:
    def maximumXor(self, s: str, t: str) -> str:
        zeros = t.count("0")
        ones = len(t) - zeros
        
        result = []
        for char in s:
            # Try to match 1 from s with 0 from t first
            if (char == "1" and zeros) or (char == "0" and ones):
                result.append("1")
                zeros -= (char == "1")
                ones -= (char == "0")
            else:
                result.append("0")
                ones -= (char == "1")
                zeros -= (char == "0")

        return "".join(result)