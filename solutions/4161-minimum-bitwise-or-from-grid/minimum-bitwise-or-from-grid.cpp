// C++
class Solution {
public:
    int minimumOR(vector<vector<int>>& grid) {
        int res = 0, f = 0;  // res = answer, f = bits we successfully set to 0 (forbidden bits)

        // Try each bit from high (17) to low (0)
        for (int i = 17; i >= 0; i--) {

            // Tentatively add current bit to forbidden mask
            int ff = f | (1 << i);

            bool found = true;  // Assume every row has a valid cell

            // Check every row
            for (auto& r : grid) {
                bool curr = false;  // Does this row have at least one valid cell?

                // Check every cell in this row
                for (auto x : r) {
                    // Cell is valid if it has NONE of the forbidden bits set
                    if ((x & ff) == 0) {
                        curr = true;  // Found a valid cell in this row
                        break;
                    }
                }

                // If no valid cell found in this row, we can't forbid this bit
                if (!curr) {
                    found = false;
                    break;
                }
            }

            if (found) {
                // Every row had a valid cell → we CAN keep this bit as 0
                // Add it to forbidden mask permanently
                f = ff;
            } else {
                // Some row had no valid cell → this bit is forced into the answer
                res |= (1 << i);
            }
        }

        return res;
    }
};