class Solution:
    def numberOfChild(self, n: int, k: int) -> int:
        n -= 1  # Decrement n to simplify calculation (so range is now 0 to n-1)
        rounds = k // n  # Calculate the number of complete back-and-forth trips
        rem = k % n  # Calculate the remaining steps after the last complete trip

        if rounds % 2 == 0:
            # If the number of complete back-and-forth trips is even
            return rem  # The ball is passed forward from the start
        else:
            # If the number of complete back-and-forth trips is odd
            return n - rem  # The ball is passed backward from the end