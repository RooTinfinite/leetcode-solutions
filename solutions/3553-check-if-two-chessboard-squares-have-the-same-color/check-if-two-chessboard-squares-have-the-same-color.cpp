class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int val1 = (coordinate1[0] - 'a' + 1 + coordinate1[1] - '0');
        int val2 = (coordinate2[0] - 'a' + 1 + coordinate2[1] - '0');
        return (val1 % 2) == (val2 % 2);
    }
};