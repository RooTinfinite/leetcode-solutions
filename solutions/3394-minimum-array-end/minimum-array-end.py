class Solution:
    def minEnd(self, n: int, x: int) -> int:

        result = 0
        # Reducing n by 1 to exclude x from the iteration
        n -= 1

        # Step 1: Initialize lists to hold the binary representation of x and n-1
        binaryX = [0] * 64  # Binary representation of x
        binaryN = [0] * 64  # Binary representation of n-1

        # Step 2: Build binary representations of x and n-1
        for i in range(64):
            bit = (x >> i) & 1  # Extract i-th bit of x
            binaryX[i] = bit

            bit = (n >> i) & 1  # Extract i-th bit of n-1
            binaryN[i] = bit

        posX = 0
        posN = 0

        # Step 3: Combine binary representation of x and n-1
        while posX < 63:
            # Traverse binaryX until we find a 0 bit
            while binaryX[posX] != 0 and posX < 63:
                posX += 1
            # Copy bits from binaryN (n-1) into binaryX (x) starting from the first 0
            binaryX[posX] = binaryN[posN]
            posX += 1
            posN += 1

        # Step 4: Rebuild the final result from the combined binary representation
        for i in range(64):
            if binaryX[i] == 1:
                # convert binary bit to decimal value
                result += pow(2, i)

        return result