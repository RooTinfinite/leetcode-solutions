class Solution:
    def digArtifacts(self, n: int, artifacts: List[List[int]], dig: List[List[int]]) -> int:
        result, dig_pos = 0, set(tuple(pos) for pos in dig)
        for pos in artifacts:
            if all((x, y) in dig_pos for x in range(pos[0], pos[2] + 1) for y in range(pos[1], pos[3] + 1)):     
                result += 1
        return result