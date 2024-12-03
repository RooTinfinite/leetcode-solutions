class Solution:
    def addSpaces(self, s: str, spaces: List[int]) -> str:
        result = [''] * (len(s) + len(spaces))
        write_pos = 0
        read_pos = 0
        
        for space_pos in spaces:
            while read_pos < space_pos:
                result[write_pos] = s[read_pos]
                write_pos += 1
                read_pos += 1
            result[write_pos] = ' '
            write_pos += 1
            
        while read_pos < len(s):
            result[write_pos] = s[read_pos]
            write_pos += 1
            read_pos += 1
            
        return ''.join(result)