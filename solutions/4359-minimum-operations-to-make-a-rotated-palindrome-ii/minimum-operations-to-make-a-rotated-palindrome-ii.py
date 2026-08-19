# NOTE: numpy convolution is >10x faster than python
def integer_fft_convolution(P, Q):
    m = len(P) + len(Q) - 1

    import numpy as np
    P = np.fft.fft(np.array(P, dtype=np.float32), m)
    Q = np.fft.fft(np.array(Q, dtype=np.float32), m)
    return np.round(np.fft.ifft(P * Q).real).astype(np.int64).tolist()


class Solution:
    def minOperations(self, s: str) -> int:
        n = len(s)

        def create_PQ(s, c):
            y = ord(c)
            a = list(s.encode("ascii"))

            P = [int(x == c) for x in s]
            Q = [min((x - y) % 26, (y - x) % 26) if x > y else 0 for x in a]
            return P, Q

        S = s + s

        ret = [0] * (3 * n)

        for c in list(set(s)):
            p,q = create_PQ(s, c)
            P,Q = create_PQ(S, c)

            conv = integer_fft_convolution(p, q)
            CONV = integer_fft_convolution(P, Q)

            for i in range(n - 1, n - 1 + 2 * n, 2):
                gain = CONV[i] - (conv[i - n] if i - n >= 0 else 0)
                ret[i] += gain

        ans = inf

        for rep in range(n):
            i = n - 1 + 2*rep
            ans = min(ans, ret[i] + rep)

        return ans