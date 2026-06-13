# PYTHON
# Python
class Solution:
    def minimumOR(self, grid: list[list[int]]) -> int:
        res, f = 0, 0  # res = answer, f = bits we successfully set to 0 (forbidden bits)

        # Try each bit from high (17) to low (0)
        for i in range(17, -1, -1):

            # Tentatively add current bit to forbidden mask
            ff = f | (1 << i)

            found = True  # Assume every row has a valid cell

            # Check every row
            for r in grid:
                curr = False  # Does this row have at least one valid cell?

                # Check every cell in this row
                for x in r:
                    # Cell is valid if it has NONE of the forbidden bits set
                    if (x & ff) == 0:
                        curr = True  # Found a valid cell in this row
                        break

                # If no valid cell found in this row, we can't forbid this bit
                if not curr:
                    found = False
                    break

            if found:
                # Every row had a valid cell → we CAN keep this bit as 0
                f = ff
            else:
                # Some row had no valid cell → this bit is forced into the answer
                res |= (1 << i)

        return res