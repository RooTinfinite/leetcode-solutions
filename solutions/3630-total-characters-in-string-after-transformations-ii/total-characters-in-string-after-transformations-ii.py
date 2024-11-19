# recursion pow

class Solution:
    def lengthAfterTransformations(self, s: str, t: int, nums: List[int]) -> int:
        alphabet = 26

        def construct_A(s):
            line = [0] * alphabet
            for char, cnt in Counter(s).items():
                index = ord(char) - 97
                line[index] = cnt
            return [line]

        def construct_B(nums):
            B = [[0] * alphabet for _ in range(alphabet)]
            for i, shift in enumerate(nums):
                for j in range(shift):
                    B[i][(i + 1 + j) % alphabet] = 1
            return B
        
        A = construct_A(s)
        B = construct_B(nums)
        modulo = 1_000_000_007

        def mult(A, B):
            n = len(A)
            m = len(B[0])
            l = len(A[0])

            C = [[0] * m for _ in range(n)]
            for i in range(n):
                for j in range(m):
                    C[i][j] = sum(
                        A[i][k] * B[k][j]
                        for k in range(l)
                    ) % modulo
            
            return C
        
        def pow(A, n):
            if n == 1:
                return A

            A_2 = mult(A, A)
            A_almost_n = pow(A_2, n // 2)
            if n % 2 == 0:
                return A_almost_n
            return mult(A, A_almost_n)
        
        C = mult(A, pow(B, t))
        return sum(
            sum(line) % modulo
            for line in C
        ) % modulo