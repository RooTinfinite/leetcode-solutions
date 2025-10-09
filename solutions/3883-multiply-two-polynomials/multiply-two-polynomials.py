import numpy as np
from numpy.polynomial.polynomial import polymul

class Solution:
    def multiply(self, poly1: List[int], poly2: List[int]) -> List[int]:
        # Solution 1: WONT WORK
        # return np.rint(polymul(poly1, poly2)).astype(np.int64).tolist()

        # Solution 3: 
        return (lst := np.rint(polymul(poly1, poly2)).astype(np.int64).tolist()) \
       + [0] * ((len(poly1) + len(poly2) - 1) - len(lst))

        # Solution 2: 
        lst = np.rint(polymul(poly1, poly2)).astype(np.int64).tolist()
        n = len(poly1) + len(poly2) - 1
        if len(lst) < n:    
            lst.extend([0] * (n - len(lst)))
        return lst

        # Solution 4: 
        n1, n2 = len(poly1), len(poly2)
        n = n1 + n2 - 1
        N = 1 << (n - 1).bit_length() # next power of 2 ≥ n, efficient FFT
        fa = np.fft.rfft(poly1, n=N)  # real‐FFT of both padded polynomials
        fb = np.fft.rfft(poly2, n=N)
        fc = fa * fb                  # pointwise product in frequency domain
        res = np.fft.irfft(fc, n=N)   # invert and take real part
        res = np.rint(res[:n]).astype(np.int64) # round to int & make len n
        return res.tolist()

        # Solution 5: Slightly optimized solution 4
        n = len(poly1) + len(poly2) - 1
        N = 1 << (n - 1).bit_length()
        r = np.fft.irfft(np.fft.rfft(poly1, n=N)*np.fft.rfft(poly2, n=N),n=N)
        return np.rint(r[:n]).astype(int).tolist()


        # Solution 6:
        # bit‐reversal permutation + in‐place Cooley–Tuk FFT
        def fft(a: List[complex], invert: bool) -> None:
            n, j = len(a), 0        # bit reversal
            for i in range(1, n):
                bit = n >> 1
                while j & bit:
                    j ^= bit
                    bit >>= 1
                j |= bit
                if i < j: a[i], a[j] = a[j], a[i]

            length = 2
            while length <= n:      # Cooley–Tuk
                ang = 2 * math.pi / length * (-1 if invert else 1)
                wlen = complex(math.cos(ang), math.sin(ang))
                for i in range(0, n, length):
                    w = 1+0j
                    half = length >> 1
                    for k in range(i, i + half):
                        u = a[k]
                        v = a[k + half] * w
                        a[k] = u + v
                        a[k + half] = u - v
                        w *= wlen
                length <<= 1

            if invert:                  # divide by n on inverse
                for i in range(n):
                    a[i] /= n


        n1, n2 = len(poly1), len(poly2)
        n = n1 + n2 - 1                 # required result length
        N = 1                           # next power of two ≥ n
        while N < n: N <<= 1

        fa = list(map(complex, poly1)) + [0]*(N - n1) # zero‐pad
        fb = list(map(complex, poly2)) + [0]*(N - n2)
        fft(fa, False)                  # forward FFT
        fft(fb, False)
        for i in range(N):
            fa[i] *= fb[i]              # point‐wise multiplication
        fft(fa, True)                   # inverse FFT

        return [int(round(fa[i].real)) for i in range(n)]