class Solution {
public:
    bool rotateString(string s, string goal) {
        // Get lengths of both strings
        int n = s.length();
        int m = goal.length();

        // If lengths are different, rotation is impossible
        if(n != m) {
            return false;
        }

        // Counter for number of rotations
        int i = 0;

        // Try all possible rotations
        while(i < n) {
            // If current string matches goal, we found a valid rotation
            if(s == goal) {
                return true;
            }

            // Perform one left rotation:
            // 1. Store first character
            char a = s[0];
            
            // 2. Shift all characters to the left by one position
            for(int j = 0; j < n-1; j++) {
                s[j] = s[j+1];
            }
            
            // 3. Place the first character at the end
            s[n-1] = a;
            
            i++;
        }

        // If we tried all rotations and found no match, return false
        return false;
    }
};