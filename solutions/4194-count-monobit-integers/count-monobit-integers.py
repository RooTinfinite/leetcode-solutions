class Solution:
    def countMonobit(self, n: int) -> int:

        bits, ones = n.bit_length(), n.bit_count()
        return bits + (ones == bits) 
        