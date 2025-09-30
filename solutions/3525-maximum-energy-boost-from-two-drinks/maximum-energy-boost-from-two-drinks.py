class Solution:
    def maxEnergyBoost(self , A , B):
        A1 = B1 = A2 = B2 = 0
        for i in range(0 , len(A)):
            currA = A[i] + max(A1, B2)
            currB = B[i] + max(B1, A2)
            A2 , A1 = A1 , currA
            B2 , B1 = B1 , currB
        return max(A1 , B1)