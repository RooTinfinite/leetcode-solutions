class Solution {
public:
    string concatHex36(int n) {
        long long n2 = 1LL * n * n;
        long long n3 = 1LL * n * n * n;

        // Convert to hexadecimal (uppercase)
        string hex_part;
        {
            stringstream ss;
            ss << uppercase << hex << n2;
            ss >> hex_part;
        }

        // Convert to base-36 (uppercase)
        string base36_chars = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
        string base36_part;

        while (n3 > 0) {
            base36_part = base36_chars[n3 % 36] + base36_part;
            n3 /= 36;
        }

        return hex_part + base36_part;
    }
};