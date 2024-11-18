class Solution:
    @staticmethod
    def mod1(i: int, n: int) -> int:
        return i - (-(i >= n) & n)
    
    def decrypt(self, circ: list[int], k: int) -> list[int]:
        n = len(circ)
        if k < 0:
            s = sum(circ[n + k:])
            circ = [v << 16 for v in circ]
            for i in range(n):
                v = circ[i] >> 16
                circ[i] += s
                j = self.mod1(n + k + i, n)
                s += v - (circ[j] >> 16)
            circ = [v & 0x3FFF for v in circ]
        elif k > 0:
            s = sum(circ[:k])
            circ = [v << 16 for v in circ]
            for i in range(n):
                v = circ[i] >> 16
                j = self.mod1(i + k, n)
                s += (circ[j] >> 16) - v
                circ[i] += s
            circ = [v & 0x3FFF for v in circ]
        else:
            circ = [0] * n
        return circ